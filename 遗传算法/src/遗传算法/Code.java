package 遗传算法;
import java.util.Random;
import java.util.Vector;
public class Code {
	private char codeType;
	private int codeLength;
	private int cNum;
	private Vector[] gene; 
	/**
	 * @param codeType 编码类型 b binary ,d decimal
	 * @param bsNum 二进制码参数个数
     * @param binCodeLength 码长
	 */
	public Code(char codeType,int cNum,int CodeLength){
		this.codeType = codeType;
		this.codeLength = CodeLength;
		this.cNum = cNum;
		this.gene = new Vector[this.cNum];
		for(int i=0;i<this.cNum;i++){
			this.gene[i] = new Vector();
		}
		Random rd = new Random();
		switch(codeType){
			case 'b':
				for(int i=0;i<this.cNum;i++){
					if(!this.gene[i].isEmpty()){
						this.gene[i].clear();
					}
					for(int j=0;j<this.codeLength;j++){
						//this.binaryGene[i].add(Integer.valueOf(rd.nextInt(2)));
						this.gene[i].add(rd.nextInt(2));
					}
				}
				break;
			case 'd':
				for(int i=0;i<this.cNum;i++){
					if(!this.gene[i].isEmpty()){
						this.gene[i].clear();
					}
					for(int j=0;j<this.codeLength;j++){
						//this.binaryGene[i].add(Integer.valueOf(rd.nextInt(2)));
						this.gene[i].add(1+rd.nextInt(this.codeLength));
					}
				}
				break;	
		}
	}
	/**
	 * 随机产生二进制编码
	 */
	public int getCodeLength() {
		return codeLength;
	}
	public void setCodeLength(int codeLength) {
		this.codeLength = codeLength;
	}
	public int getCNum() {
		return cNum;
	}
	public void setCNum(int cNum) {
		this.cNum = cNum;
	}
	public Vector[] getGene() {
		return gene;
	}
	public void setGene(Vector[] binaryGene) {
		this.gene = binaryGene;
	}
	public char getCodeType() {
		return codeType;
	}
	public void setCodeType(char codeType) {
		this.codeType = codeType;
	}

}
