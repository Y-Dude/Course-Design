package �Ŵ��㷨;

import java.util.Vector;
import java.util.Random;
import javax.swing.ProgressMonitor;
public class Population {
	private int populationNum;
	private int selectionID;
	private int crossID;
	private int genovariationID;
	private int iterateNum;
	private int showStyle;
	private double pc;
	private double pv;
	private Function ef;
	private int bestGene;
	private Gene sumGene;
	private Gene avgGene;
	private Gene[] genes;
	private StringBuffer sbInitGenes;
/**
 * 
 * @param populationNum ��Ⱥ��ģ
 * @param iterateNum ��������
 * @param pc �������
 * @param pv �������
 * @param ef ��������
 */	
	public Population(int populationNumv,int iterateNumv,int selectionIDv,int crossIDv,int genovariationIDv,double pc,double pv,Function ef,int showStyle){
		this.populationNum = populationNumv;
		this.selectionID = selectionIDv;
		this.crossID = crossIDv;
		this.genovariationID = genovariationIDv;
		this.iterateNum = iterateNumv;
		this.pc = pc;
		this.pv = pv;
		this.ef = ef;
		this.showStyle = showStyle;
		this.sumGene = new Gene();
		this.avgGene = new Gene();
		this.sbInitGenes = new StringBuffer();
		/**
		 * ��ʼ����Ⱥ
		 * һ��Ҫע���BinaryGene bc  =new BinaryGene(parameterNum,codeLen) ����ѭ���ڲ�
		 */
		int codeLen= ef.getCodeLen();
		int parameterNum = ef.getParameterNum();
		this.genes = new Gene[populationNum];
		for(int i=0;i<populationNum;i++){
			Code bc  =new Code(ef.getCodeType(),parameterNum,codeLen);
			genes[i] = new Gene();
			genes[i].setGeneID(i);
			Vector[] vecGene =  bc.getGene();
			genes[i].setVecGene(vecGene);
			genes[i].setEvaluateValue(ef.fun(vecGene));	
		}
		genes = calculateRoulette(genes);
		/**
		 * �������ѡ�񣬽��棬����
		 */
		sbInitGenes = ef.getSbLastGenes(this.showStyle,genes); 
		final  ProgressMonitor pm = new ProgressMonitor(null,"�������ڼ���......","��ǰ���У�0%",0,iterateNum);
		 pm.setMillisToPopup(0);
		 pm.setMillisToDecideToPopup(0);
		for(int i=0;i<iterateNum;i++){ 
			pm.setProgress(i);
			pm.setNote("��ǰ���У�"+ef.doubleToString(2,(i*100.00)/iterateNum)+" %");
			genes = selection(selectionID,genes);
			genes = cross(crossID,genes); 
			genes = genovariation(genovariationID,genes);
			genes = calculateRoulette(genes);
		}
		 pm.close();
	}
	/**
	 * @param targetGene δ��Ӷ���ֵ�û��򣬸û���ֻ�б������Ӧ�Ⱥ���ֵ
	 * @return ���ݸû�������� �����´�����ѡ��Ļ���
	 */
	public Gene[] calculateRoulette(Gene[] targetGene){
		double sumEvaluateValue =0;
		for(int i=0;i<populationNum;i++){
			/**
			 * ��ʼ��Ϊ0
			 */
			targetGene[i].setSelectProbability(0);
			targetGene[i].setExpectValue(0);
			targetGene[i].setRouletteNum(0);
			sumEvaluateValue = sumEvaluateValue +targetGene[i].getEvaluateValue();
		}
		this.sumGene.setEvaluateValue(sumEvaluateValue);
		this.avgGene.setEvaluateValue(sumEvaluateValue/populationNum);
		this.sumGene.setSelectProbability((double)1);
		this.avgGene.setSelectProbability((double)1/populationNum);
		this.sumGene.setExpectValue(populationNum);
		this.avgGene.setExpectValue((double)1);
		double minev = this.avgGene.getExpectValue();//��С����ֵ,��ʼ��Ϊƽ������ֵ
		for(int i=0;i<populationNum;i++){ //��ѡ����ʺ���Ӧ��������ֵ
			double sp = targetGene[i].getEvaluateValue()/this.sumGene.getEvaluateValue();
			double ev = targetGene[i].getEvaluateValue()/this.avgGene.getEvaluateValue();
			targetGene[i].setSelectProbability(sp);
			targetGene[i].setExpectValue(ev);
			if(sp<=minev){ //ȡ����С����ֵ����
				minev = sp;
				this.bestGene = i;
			}
		}
		/**
		 * ʹ�ö��ַ�ѡ�����
		 */
		int counter = 0 ;
		for(int i=0;i<this.populationNum;i++){
			if((int)targetGene[i].getExpectValue()==0){
				targetGene[i].setRouletteNum(targetGene[i].getRouletteNum()+1);
				counter++;
			}
		}
		int index=1; //��ʶ��鵽С������indexΪ����ѡ�񹻻���
		while(counter<this.getPopulationNum()){
			for(int i=0;i<10;i++){	
				for(int j=0;j<this.populationNum;j++){
					if(ef.getNum(targetGene[j].getExpectValue(),index)==i){
						if(counter>=this.populationNum){
							break;
						}
						else{
							targetGene[j].setRouletteNum(targetGene[j].getRouletteNum()+1);
							counter++;
						}
					}
				}
			}
			index++;
		}
		return targetGene;
	}
	public Gene[] selection(int selectionID,Gene[] targetGene){
		
		switch(selectionID){
		case 1:
			int pointer0 = 0;
			for(int i=0;i<this.populationNum;i++){
				if (targetGene[i].getRouletteNum()>1){
					for(int j=pointer0;j<this.populationNum;j++){
						if (targetGene[j].getRouletteNum()==0){
							pointer0 = j+1; //��¼��һ��ѭ���Ŀ�ʼλ��
							/**
							 * �˴�һ��Ҫ���¿��������ռ䣬����ʹ��targetGene[j].setVecGene(vecGenetargetGene[i].getVecGene()[k]);
							 * ��ֻ��������ַָ��
							 */
							Vector[] vecGene = new Vector[ef.getParameterNum()];
							for(int k=0;k<ef.getParameterNum();k++){
								vecGene[k] = new Vector();
								vecGene[k].addAll(targetGene[i].getVecGene()[k]);
							}
							targetGene[j].setVecGene(vecGene);
							targetGene[j].setEvaluateValue(targetGene[i].getEvaluateValue());
							targetGene[j].setRouletteNum(targetGene[j].getRouletteNum()+1);
							targetGene[i].setRouletteNum(targetGene[i].getRouletteNum()-1);
							break;
						}
					}
				}	
			}
		return targetGene;
		default:
			return targetGene;
		}
		
}
	/**
	 * @param crossID ����ķ���
	 * @param targetGene Ŀ�������
	 * @return ���ؽ����Ļ���
	 */
	public Gene[] cross(int crossID,Gene[] targetGene){
		switch(crossID){
		case 1:
			/**
			 * ���㽻��
			 */
			for(int i=0;i<this.populationNum;i++){
				Random rd = new Random();
				double randomPc = rd.nextDouble();
				if(randomPc<=this.pc){
					int randoma,randomb,randomPosition;
					int codeLen= this.ef.getCodeLen();
					randoma = rd.nextInt(this.populationNum); //�������a
					randomb = rd.nextInt(this.populationNum); //�������b
					for(int j=0;j<ef.getParameterNum();j++){
						randomPosition = rd.nextInt(codeLen); //�������λ 					
						for(int k=0;k<randomPosition;k++){
							int temp;
							temp = ef.stringToInt(targetGene[randoma].getVecGene()[j].elementAt(k).toString());
							targetGene[randoma].getVecGene()[j].setElementAt(targetGene[randomb].getVecGene()[j].elementAt(k),k);
							targetGene[randomb].getVecGene()[j].setElementAt(temp, k);
						}
					}
				}
			}
			/**
			 * ��������¼�����Ӧ��ֵ
			 */
			for(int i=0;i<this.populationNum;i++){
				targetGene[i].setEvaluateValue(ef.fun(targetGene[i].getVecGene()));
			}
			return targetGene;
			default:
				return targetGene;
		}
	}
	/**
	 * @param genovariationID
	 * @param targetGene
	 * @return
	 */
	public Gene[] genovariation(int genovariationID,Gene[] targetGene){
		switch(genovariationID){
		case 1:
			for(int i=0;i<this.populationNum;i++){
				for(int j=0;j<ef.getParameterNum();j++){
					for(int k=0;k<ef.getCodeLen();k++){
						Random rd = new Random();
						double random = rd.nextDouble();
						if(random< this.pv){
							if(ef.stringToInt(targetGene[i].getVecGene()[j].elementAt(k).toString())==0){
								targetGene[i].getVecGene()[j].setElementAt(1, k);
							}
							else{
								targetGene[i].getVecGene()[j].setElementAt(0, k);
							}
						}	
					}
				}
		
			}

			/**
			 * ��������¼�����Ӧ��ֵ
			 */
			for(int i=0;i<this.populationNum;i++){
				targetGene[i].setEvaluateValue(ef.fun(targetGene[i].getVecGene()));
			}
			return targetGene;
		case 2:
			default:
				return targetGene;	
		}		
	}	
	/**
	 * @param precision ָ���ַ����ľ���
	 * @param d double���͵�ֵ
	 * @return
	 */

	public Gene[] getGenes() {
		return genes;
	}
	public void setGenes(Gene[] genes) {
		this.genes = genes;
	}
	public Gene getAvgGene() {
		return avgGene;
	}
	public void setAvgGene(Gene avgGene) {
		this.avgGene = avgGene;
	}
	public int getBestGene() {
		return bestGene;
	}
	public void setBestGene(int bestGene) {
		this.bestGene = bestGene;
	}
	public int getPopulationNum() {
		return populationNum;
	}
	public void setPopulationNum(int populationNum) {
		this.populationNum = populationNum;
	}
	public Gene getSumGene() {
		return sumGene;
	}
	public void setSumGene(Gene sumGene) {
		this.sumGene = sumGene;
	}
	public int getCrossID() {
		return crossID;
	}
	public void setCrossID(int crossID) {
		this.crossID = crossID;
	}
	public Function getEf() {
		return ef;
	}
	public void setEf(Function ef) {
		this.ef = ef;
	}
	public int getGenovariationID() {
		return genovariationID;
	}
	public void setGenovariationID(int genovariationID) {
		this.genovariationID = genovariationID;
	}
	public double getPc() {
		return pc;
	}
	public void setPc(double pc) {
		this.pc = pc;
	}
	public double getPv() {
		return pv;
	}
	public void setPv(double pv) {
		this.pv = pv;
	}
	public int getSelectionID() {
		return selectionID;
	}
	public void setSelectionID(int selectionID) {
		this.selectionID = selectionID;
	}
	public int getIterateNum() {
		return iterateNum;
	}
	public void setIterateNum(int iterateNum) {
		this.iterateNum = iterateNum;
	}
	public StringBuffer getSbInitGenes() {
		return sbInitGenes;
	}
	public void setSbInitGenes(StringBuffer sbInitGenes) {
		this.sbInitGenes = sbInitGenes;
	}
}
