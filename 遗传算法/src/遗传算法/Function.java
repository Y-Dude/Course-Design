package �Ŵ��㷨;
import java.text.DecimalFormat;
import java.util.Vector;

public class Function {
	private int funID;
	private char codeType;
	private int parameterNum;
	private int precision;
	private double maxValue;
	private double minValue;
	private String codeName,selectionName,crossName,genovariationName;
	private StringBuffer sbBestGeneetail;
	private StringBuffer sblastGenes;
	/**
	 * @param funID ������ʶ
	 * @param codeType �������� b binary
	 * @param parameterNum �����Ĳ�������
	 * @param precision Ҫ��ľ�ȷ��
	 * @param maxValue ���������ֵ
	 * @param minValue ��������Сֵ
	 */
	public Function(int funID,char codeType,int precision){
		this.funID = funID;
		this.codeType = codeType;
		this.precision = precision;	
		this.sbBestGeneetail = new StringBuffer();
		this.sblastGenes = new StringBuffer();
		switch(funID){
		case 1:
			this.parameterNum =2;
			this.maxValue = 10;
			this.minValue = 0;	
			break;
		case 2:
			this.parameterNum =2;
			this.maxValue = 10;
			this.minValue = -10;	
			break;
			default:break;
		}
	}
	public int getFunID() {
		return funID;
	}
	public void setFunID(int funID) {
		this.funID = funID;
	}
	public double getMaxValue() {
		return maxValue;
	}
	public void setMaxValue(double maxValue) {
		this.maxValue = maxValue;
	}
	public double getMinValue() {
		return minValue;
	}
	public void setMinValue(double minValue) {
		this.minValue = minValue;
	}
	public int getParameterNum() {
		return parameterNum;
	}
	public void setParameterNum(int parameterNum) {
		this.parameterNum = parameterNum;
	}
	public int getPrecision() {
		return precision;
	}
	public void setPrecision(int precision) {
		this.precision = precision;
	}
	public char getCodeType() {
		return codeType;
	}
	public void setCodeType(char codeType) {
		this.codeType = codeType;
	}
/**
 * @param str Ҫ������Ϊ�����ַ�����������Ϊ��ĸ�������ַ�
 * @return
 */
	public int stringToInt(String str){
		return Integer.valueOf(str).intValue();
	}
/**
 * ��������Ʊ����ʮ����ֵ
 * @param vecBc ����vector���͵Ķ������봮
 * @return ��Ӧ��ʮ������
 */
	public int binaryToDecimal(Vector vecBc){
		int intDec = 0;
		for(int i=0;i<vecBc.size();i++){
			intDec = intDec+(int)(stringToInt(vecBc.elementAt(i).toString())*Math.pow((double)2,(double)(vecBc.size()-1 -i)));	
			//Math.pow(x,y)x������y����
		}
		return intDec;	
	}
	/**
	 * ���ݾ��ȺͶ�����[u,v]�����볤L
	 * ���㷽����
	 * L=(int)floor(log(v-u)/log(2.0))+1
	 * floor��x����x����ȡ����floor(9.999999) = 9.0
	 * ���׹�ʽ��log(x)(y) =log(e)(x) / log(e)(y)��
	 * log(2)(1000)�ļ�����Math.log(1000) / Math.log(2)
	 * double minValue ��������Ͻ�
	 * double maxValue ��������½�
	 * int precision Ҫ��ľ���
	 * ע��log������double��
	 */
	public int getCodeLen(){
		int len=0;
		len = (int)Math.floor(Math.log((this.maxValue-this.minValue)*Math.pow((double)10,(double)this.precision))/Math.log(2))+1;
		return len;
	}
/**
 * ����Ӧ�ڶ������ϵ�ʵ��ֵ
 * x= u+x'(v-u)/(2^��L-1��)
 * @param decimalValue �����ƶ�Ӧ��ʮ������
 * @return ʵ��ֵ
 */
	public double getReal(int decimalValue){
		double cr =0;
		int codeLen;
		codeLen = getCodeLen();
		cr = minValue+decimalValue*((this.maxValue-this.minValue)/(Math.pow((double)2,(double)codeLen)-1));
		return cr;
	}
/**
 * @param number ȡdouble�������ݵ�С������indexλֵ
 * @param index λ��
 * @return
 */
	public int getNum(double number,int index){
		int num = 0;
		for(int i=0;i<index;i++){
			number = number - (int)number;
			num = (int)(number*(int)Math.pow(10, index))%10;
		}
		return num;	
	}

	public String doubleToString(int precision,double d){
		String str = "0.";
		for(int i=0;i<precision;i++){
			str = str +"0";
		}
		return  new DecimalFormat(str).format(d);
	}
	
		/**
	 * @param printID ��ӡ�ķ�ʽ  
	 * @param targetGene
	 */
	public StringBuffer getSbLastGenes(int printID,Gene[] targetGene){
		switch(printID){
		case 2:
			this.sblastGenes.delete(0, this.sblastGenes.length());
			for(int i=0;i<targetGene.length;i++){
				this.sblastGenes.append("�����ţ� "+targetGene[i].getGeneID()+"\n");
				for(int j =0;j<targetGene[i].getVecGene().length;j++){
					this.sblastGenes.append("��������ֵ: "+targetGene[i].getVecGene()[j]+"  ʮ������ֵ: "+ binaryToDecimal(targetGene[i].getVecGene()[j])+"  ��ʵֵ: X"+j+": "+doubleToString(this.precision,getReal(binaryToDecimal(targetGene[i].getVecGene()[j])))+"\n");
				}
				this.sblastGenes.append("��Ӧ����ֵ "+doubleToString(this.precision,targetGene[i].getEvaluateValue())+" , ");
				this.sblastGenes.append("ѡ�����-f(x)/sum(f(x)) =  "+doubleToString(this.precision,targetGene[i].getSelectProbability())+" , ");
				this.sblastGenes.append("����ֵ-f(x)/avg(f(x)) =  "+doubleToString(this.precision,targetGene[i].getExpectValue())+" , ");
				this.sblastGenes.append("������ rouletteNum = "+targetGene[i].getRouletteNum()+" \n");
				this.sblastGenes.append("��������ֵ��"+doubleToString(this.precision, evaluateFun(targetGene[i].getVecGene()))+"\n");
				this.sblastGenes.append("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				}
			return this.sblastGenes;
			default:
				return this.sblastGenes;
		}
	}
	/**
	 * @param population
	 * @return
	 */
	public StringBuffer getSbBestGeneetail(Population population){
		if(this.codeType=='b'){
			this.codeName = "�����Ʊ���";
		}
		else{
			this.codeName = "";
		}
		if(population.getSelectionID()==1){
			this.selectionName = "����ѡ��";
		}
		else{
			this.selectionName = "";
		}
		if(population.getCrossID()==1){
			this.crossName = "���㽻��";
		}
		else{
			this.crossName = "";
		}
		if(population.getGenovariationID()==1){
			this.genovariationName = "�����";
		}
		else{
			this.genovariationName = "";
		}
		
		Gene bestGene = population.getGenes()[population.getBestGene()];
		this.sbBestGeneetail.delete(0, this.sbBestGeneetail.length());
		
		this.sbBestGeneetail.append("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		this.sbBestGeneetail.append("ϵͳ�Ĳ������£�\n");
		this.sbBestGeneetail.append("����: F"+population.getEf().funID+" �����뷽ʽ��"+this.codeName+" ��ѡ���㷨��"+this.selectionName+" �������㷨��"+this.crossName+" �������㷨��"+this.genovariationName+"\n");
		this.sbBestGeneetail.append("��Ⱥ��ģ��"+population.getPopulationNum()+" ,������ʣ�"+population.getPc()+" ,������ʣ�"+population.getPv()+" ,����������"+population.getIterateNum()+"\n");
		this.sbBestGeneetail.append("��Ⱥ���Ÿ���Ϊ��"+population.getBestGene()+" ");
		this.sbBestGeneetail.append("��Ӧ�Ⱥ���ֵ :"+doubleToString(this.precision,bestGene.getEvaluateValue())+" , ");
		this.sbBestGeneetail.append("ѡ����� :"+doubleToString(this.precision,bestGene.getSelectProbability())+" , ");
		this.sbBestGeneetail.append("����ֵ :"+doubleToString(this.precision,bestGene.getExpectValue())+" , ");
		this.sbBestGeneetail.append("����ֵ�� "+bestGene.getRouletteNum()+"\n");
		this.sbBestGeneetail.append("��������Ϊ�� ");
		for(int i =0;i<bestGene.getVecGene().length;i++){
			this.sbBestGeneetail.append("X"+i+"= "+doubleToString(this.precision,getReal(binaryToDecimal(bestGene.getVecGene()[i])))+" , ");
		}
		this.sbBestGeneetail.append("�ú�������СֵΪ��"+doubleToString(this.precision, evaluateFun(bestGene.getVecGene()))+"\n");
		return this.sbBestGeneetail;
	}
	/**
	 * �˴�Ϊ����������
	 */
	/**
	 * ����Ϊ��������
	 * ���Ϊdouble
	 */
	public double fun(Vector[] vc){
		double funValue = 0;	
		switch(this.funID){
		case 1:
			funValue = funValue + getReal(binaryToDecimal(vc[0]));
			return funValue;
		case 2:
			funValue =Math.pow(getReal(binaryToDecimal(vc[0])),2)+Math.pow(getReal(binaryToDecimal(vc[1])),2);
			return funValue;
		default : return funValue;
		}
	}
		public double evaluateFun(Vector[] vc){
		double funValue = 0;
		switch(this.funID){
		case 1:
			funValue = funValue + getReal(binaryToDecimal(vc[0]));
			return funValue;
		case 2:
			return funValue = Math.pow(getReal(binaryToDecimal(vc[0])),2)+Math.pow(getReal(binaryToDecimal(vc[1])),2);
		default : return funValue;
		}
	}
}
