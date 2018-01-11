package 遗传算法;
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
	 * @param funID 函数标识
	 * @param codeType 编码类型 b binary
	 * @param parameterNum 函数的参数个数
	 * @param precision 要求的精确度
	 * @param maxValue 定义域最大值
	 * @param minValue 定义域最小值
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
 * @param str 要求输入为数字字符串，不可以为字母等其他字符
 * @return
 */
	public int stringToInt(String str){
		return Integer.valueOf(str).intValue();
	}
/**
 * 计算二进制编码的十进制值
 * @param vecBc 输入vector类型的二进制码串
 * @return 对应的十进制数
 */
	public int binaryToDecimal(Vector vecBc){
		int intDec = 0;
		for(int i=0;i<vecBc.size();i++){
			intDec = intDec+(int)(stringToInt(vecBc.elementAt(i).toString())*Math.pow((double)2,(double)(vecBc.size()-1 -i)));	
			//Math.pow(x,y)x底数，y幂数
		}
		return intDec;	
	}
	/**
	 * 根据精度和定义域[u,v]计算码长L
	 * 计算方法：
	 * L=(int)floor(log(v-u)/log(2.0))+1
	 * floor（x）对x向下取整数floor(9.999999) = 9.0
	 * 换底公式：log(x)(y) =log(e)(x) / log(e)(y)，
	 * log(2)(1000)的计算结果Math.log(1000) / Math.log(2)
	 * double minValue 定义域的上界
	 * double maxValue 定义域的下界
	 * int precision 要求的精度
	 * 注：log本身返回double型
	 */
	public int getCodeLen(){
		int len=0;
		len = (int)Math.floor(Math.log((this.maxValue-this.minValue)*Math.pow((double)10,(double)this.precision))/Math.log(2))+1;
		return len;
	}
/**
 * 求解对应于定义域上的实数值
 * x= u+x'(v-u)/(2^（L-1）)
 * @param decimalValue 二进制对应的十进制数
 * @return 实数值
 */
	public double getReal(int decimalValue){
		double cr =0;
		int codeLen;
		codeLen = getCodeLen();
		cr = minValue+decimalValue*((this.maxValue-this.minValue)/(Math.pow((double)2,(double)codeLen)-1));
		return cr;
	}
/**
 * @param number 取double类型数据的小数点后第index位值
 * @param index 位数
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
	 * @param printID 打印的方式  
	 * @param targetGene
	 */
	public StringBuffer getSbLastGenes(int printID,Gene[] targetGene){
		switch(printID){
		case 2:
			this.sblastGenes.delete(0, this.sblastGenes.length());
			for(int i=0;i<targetGene.length;i++){
				this.sblastGenes.append("基因编号： "+targetGene[i].getGeneID()+"\n");
				for(int j =0;j<targetGene[i].getVecGene().length;j++){
					this.sblastGenes.append("二进制码值: "+targetGene[i].getVecGene()[j]+"  十进制码值: "+ binaryToDecimal(targetGene[i].getVecGene()[j])+"  真实值: X"+j+": "+doubleToString(this.precision,getReal(binaryToDecimal(targetGene[i].getVecGene()[j])))+"\n");
				}
				this.sblastGenes.append("适应函数值 "+doubleToString(this.precision,targetGene[i].getEvaluateValue())+" , ");
				this.sblastGenes.append("选择概率-f(x)/sum(f(x)) =  "+doubleToString(this.precision,targetGene[i].getSelectProbability())+" , ");
				this.sblastGenes.append("期望值-f(x)/avg(f(x)) =  "+doubleToString(this.precision,targetGene[i].getExpectValue())+" , ");
				this.sblastGenes.append("赌轮数 rouletteNum = "+targetGene[i].getRouletteNum()+" \n");
				this.sblastGenes.append("评估函数值："+doubleToString(this.precision, evaluateFun(targetGene[i].getVecGene()))+"\n");
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
			this.codeName = "二进制编码";
		}
		else{
			this.codeName = "";
		}
		if(population.getSelectionID()==1){
			this.selectionName = "赌轮选择法";
		}
		else{
			this.selectionName = "";
		}
		if(population.getCrossID()==1){
			this.crossName = "单点交叉";
		}
		else{
			this.crossName = "";
		}
		if(population.getGenovariationID()==1){
			this.genovariationName = "点变异";
		}
		else{
			this.genovariationName = "";
		}
		
		Gene bestGene = population.getGenes()[population.getBestGene()];
		this.sbBestGeneetail.delete(0, this.sbBestGeneetail.length());
		
		this.sbBestGeneetail.append("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		this.sbBestGeneetail.append("系统的参数如下：\n");
		this.sbBestGeneetail.append("函数: F"+population.getEf().funID+" ；编码方式："+this.codeName+" ；选择算法："+this.selectionName+" ；交叉算法："+this.crossName+" ；变异算法："+this.genovariationName+"\n");
		this.sbBestGeneetail.append("种群规模："+population.getPopulationNum()+" ,交叉概率："+population.getPc()+" ,变异概率："+population.getPv()+" ,迭代次数："+population.getIterateNum()+"\n");
		this.sbBestGeneetail.append("种群最优个体为："+population.getBestGene()+" ");
		this.sbBestGeneetail.append("适应度函数值 :"+doubleToString(this.precision,bestGene.getEvaluateValue())+" , ");
		this.sbBestGeneetail.append("选择概率 :"+doubleToString(this.precision,bestGene.getSelectProbability())+" , ");
		this.sbBestGeneetail.append("期望值 :"+doubleToString(this.precision,bestGene.getExpectValue())+" , ");
		this.sbBestGeneetail.append("赌轮值： "+bestGene.getRouletteNum()+"\n");
		this.sbBestGeneetail.append("函数参数为： ");
		for(int i =0;i<bestGene.getVecGene().length;i++){
			this.sbBestGeneetail.append("X"+i+"= "+doubleToString(this.precision,getReal(binaryToDecimal(bestGene.getVecGene()[i])))+" , ");
		}
		this.sbBestGeneetail.append("该函数的最小值为："+doubleToString(this.precision, evaluateFun(bestGene.getVecGene()))+"\n");
		return this.sbBestGeneetail;
	}
	/**
	 * 此处为评估函数库
	 */
	/**
	 * 输入为参数集合
	 * 输出为double
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
