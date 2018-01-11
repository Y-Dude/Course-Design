package �Ŵ��㷨;
import java.util.Vector;
public class Gene {
	private int geneID;
	private Vector[] vecGene;
	private double evaluateValue;
	private double selectProbability;
	private double expectValue;
	private int rouletteNum;
	/**
	 * @param geneID �����ʶ
	 * @param vecGene ����ֵ
	 * @param evaluateValue ��Ӧֵ
	 * @param selectProbability ѡ�����
	 * @param expectValue ����ֵ
	 * @param rouletteNum ������
	 */
	public int getGeneID() {
		return geneID;
	}
	public void setGeneID(int geneID) {
		this.geneID = geneID;
	}
	
	public Vector[] getVecGene() {
		return this.vecGene;
	}
	public void setVecGene(Vector[] vecGene) {
		this.vecGene = vecGene;
	}
	
	public double getEvaluateValue() {
		return evaluateValue;
	}
	public void setEvaluateValue(double evaluateValue) {
		this.evaluateValue = evaluateValue;
	}
	
	public double getExpectValue() {
		return expectValue;
	}
	public void setExpectValue(double expectValue) {
		this.expectValue = expectValue;
	}
	
	public int getRouletteNum() {
		return rouletteNum;
	}
	public void setRouletteNum(int rouletteNum) {
		this.rouletteNum = rouletteNum;
	}
	
	public double getSelectProbability() {
		return selectProbability;
	}
	public void setSelectProbability(double selectProbability) {
		this.selectProbability = selectProbability;
	}
}
