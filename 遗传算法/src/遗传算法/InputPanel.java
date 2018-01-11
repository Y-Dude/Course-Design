package 遗传算法;

import java.awt.*;
import javax.swing.*;

public class InputPanel extends JPanel {
	private static final long serialVersionUID = 1L;
	private static final int MAXHEIGHT = 200,MAXWIDTH = 800;
	private JLabel instructionLabel;
	private JComboBox cbFun;
	private JLabel labPopulationNum,labCrossP,labGenovariationP,labPrecision,labIterateNum;
	private JSpinner spinPopulationNum,spinCrossP,spinGenovariationP,spinPrecision,spinIterateNum;
	private JLabel funIconShow;
	private JPanel upPanel,centerPanel,downPanel;
	public InputPanel() {
		this.setSize(MAXWIDTH, MAXHEIGHT);
		this.setLayout(new BorderLayout(10,0));
		this.upPanel = new JPanel();
		this.centerPanel = new JPanel();
		this.centerPanel.setSize(800,500);
		this.downPanel = new JPanel();
		this.upPanel.setLayout(new BorderLayout());
		//create leftpart begin
		this.instructionLabel = new JLabel("提示: 种群规模 20～200；交叉概率：0.6～1.0；变异概率：0.005～0.01;精度位数：1～8.");
		this.cbFun  = new JComboBox();
		cbFun.addItem("选择函数");
		cbFun.addItem("f(x)=x[0,10]");
		cbFun.addItem("f(x)=x*x+y*y[-10,10]");
		upPanel.add(this.instructionLabel,BorderLayout.NORTH);
		centerPanel.add(cbFun);
		labPopulationNum =new JLabel("种群规模:");
		SpinnerNumberModel modelPN = new SpinnerNumberModel(20,20,200,1);
		//JSpinner可调框内（初始值20，最小值20，最大值200，增量1）
		spinPopulationNum = new JSpinner(modelPN);
		spinPopulationNum.setSize(5,5);
		labCrossP=new JLabel("交叉概率:");
		SpinnerNumberModel modelCP = new SpinnerNumberModel(0.8,0.6,1.0,0.1);
		spinCrossP= new JSpinner(modelCP);
		labGenovariationP=new JLabel("变异概率:");
		SpinnerNumberModel modelGP = new SpinnerNumberModel(0.005,0.005,0.01,0.001);
		spinGenovariationP= new JSpinner(modelGP);
		labPrecision = new JLabel("要求精度位数:");
		SpinnerNumberModel modelP = new SpinnerNumberModel(2,1,8,1);
		spinPrecision = new JSpinner(modelP);
		labIterateNum = new JLabel("迭代次数：");
		SpinnerNumberModel modelIN = new SpinnerNumberModel(40,1,10000,1);
		spinIterateNum = new JSpinner(modelIN);

		downPanel.add(this.labPopulationNum);
		downPanel.add(this.spinPopulationNum);
		downPanel.add(this.labCrossP);
		downPanel.add(this.spinCrossP);
		downPanel.add(this.labGenovariationP);
		downPanel.add(this.spinGenovariationP);
		downPanel.add(this.labPrecision);
		downPanel.add(this.spinPrecision);
		downPanel.add(this.labIterateNum);
		downPanel.add(this.spinIterateNum);
		//create rightpart end;
		this.add(upPanel,BorderLayout.NORTH);
		this.add(centerPanel,BorderLayout.CENTER);
		this.add(downPanel,BorderLayout.SOUTH);
	}
//函数选择
	public JComboBox getCbFun() {
		return cbFun;
	}
	public void setCbFun(JComboBox cbFun) {
		this.cbFun = cbFun;
	}
	//提示
	public JLabel getInstructionLabel() {
		return instructionLabel;
	}
	public void setInstructionLabel(JLabel instructionLabel) {
		this.instructionLabel = instructionLabel;
	}
	//交叉概率
	public JSpinner getSpinCrossP() {
		return spinCrossP;
	}
	public void setSpinCrossP(JSpinner spinCrossP) {
		this.spinCrossP = spinCrossP;
	}
	//变异概率
	public JSpinner getSpinGenovariationP() {
		return spinGenovariationP;
	}
	public void setSpinGenovariationP(JSpinner spinGenovariationP) {
		this.spinGenovariationP = spinGenovariationP;
	}
	//迭代次数
	public JSpinner getSpinIterateNum() {
		return spinIterateNum;
	}
	public void setSpinIterateNum(JSpinner spinIterateNum) {
		this.spinIterateNum = spinIterateNum;
	}
	//种群规模
	public JSpinner getSpinPopulationNum() {
		return spinPopulationNum;
	}
	public void setSpinPopulationNum(JSpinner spinPopulationNum) {
		this.spinPopulationNum = spinPopulationNum;
	}
	//精度
	public JSpinner getSpinPrecision() {
		return spinPrecision;
	}
	public void setSpinPrecision(JSpinner spinPrecision) {
		this.spinPrecision = spinPrecision;
	}
}
