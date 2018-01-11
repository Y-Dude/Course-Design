package 遗传算法;

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
 * @param populationNum 种群规模
 * @param iterateNum 迭代次数
 * @param pc 交叉概率
 * @param pv 变异概率
 * @param ef 评估函数
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
		 * 初始化种群
		 * 一定要注意把BinaryGene bc  =new BinaryGene(parameterNum,codeLen) 放入循环内部
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
		 * 下面调用选择，交叉，变异
		 */
		sbInitGenes = ef.getSbLastGenes(this.showStyle,genes); 
		final  ProgressMonitor pm = new ProgressMonitor(null,"程序正在计算......","当前运行：0%",0,iterateNum);
		 pm.setMillisToPopup(0);
		 pm.setMillisToDecideToPopup(0);
		for(int i=0;i<iterateNum;i++){ 
			pm.setProgress(i);
			pm.setNote("当前运行："+ef.doubleToString(2,(i*100.00)/iterateNum)+" %");
			genes = selection(selectionID,genes);
			genes = cross(crossID,genes); 
			genes = genovariation(genovariationID,genes);
			genes = calculateRoulette(genes);
		}
		 pm.close();
	}
	/**
	 * @param targetGene 未添加赌轮值得基因，该基因只有编码和适应度函数值
	 * @return 根据该基因的特征 生成下代可以选择的基因
	 */
	public Gene[] calculateRoulette(Gene[] targetGene){
		double sumEvaluateValue =0;
		for(int i=0;i<populationNum;i++){
			/**
			 * 初始化为0
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
		double minev = this.avgGene.getExpectValue();//最小期望值,初始化为平均期望值
		for(int i=0;i<populationNum;i++){ //求选择概率和适应函数期望值
			double sp = targetGene[i].getEvaluateValue()/this.sumGene.getEvaluateValue();
			double ev = targetGene[i].getEvaluateValue()/this.avgGene.getEvaluateValue();
			targetGene[i].setSelectProbability(sp);
			targetGene[i].setExpectValue(ev);
			if(sp<=minev){ //取出最小期望值基因
				minev = sp;
				this.bestGene = i;
			}
		}
		/**
		 * 使用赌轮法选择基因
		 */
		int counter = 0 ;
		for(int i=0;i<this.populationNum;i++){
			if((int)targetGene[i].getExpectValue()==0){
				targetGene[i].setRouletteNum(targetGene[i].getRouletteNum()+1);
				counter++;
			}
		}
		int index=1; //标识检查到小数点后第index为即可选择够基因
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
							pointer0 = j+1; //记录下一次循环的开始位置
							/**
							 * 此处一定要重新开辟向量空间，不能使用targetGene[j].setVecGene(vecGenetargetGene[i].getVecGene()[k]);
							 * 那只是向量地址指向
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
	 * @param crossID 交叉的方法
	 * @param targetGene 目标基因组
	 * @return 返回交叉后的基因
	 */
	public Gene[] cross(int crossID,Gene[] targetGene){
		switch(crossID){
		case 1:
			/**
			 * 单点交叉
			 */
			for(int i=0;i<this.populationNum;i++){
				Random rd = new Random();
				double randomPc = rd.nextDouble();
				if(randomPc<=this.pc){
					int randoma,randomb,randomPosition;
					int codeLen= this.ef.getCodeLen();
					randoma = rd.nextInt(this.populationNum); //随机基因a
					randomb = rd.nextInt(this.populationNum); //随机基因b
					for(int j=0;j<ef.getParameterNum();j++){
						randomPosition = rd.nextInt(codeLen); //交叉随机位 					
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
			 * 交叉后重新计算适应度值
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
			 * 变异后重新计算适应度值
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
	 * @param precision 指定字符串的精度
	 * @param d double类型的值
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
