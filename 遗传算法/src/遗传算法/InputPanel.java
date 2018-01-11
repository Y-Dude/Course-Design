package �Ŵ��㷨;

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
		this.instructionLabel = new JLabel("��ʾ: ��Ⱥ��ģ 20��200��������ʣ�0.6��1.0��������ʣ�0.005��0.01;����λ����1��8.");
		this.cbFun  = new JComboBox();
		cbFun.addItem("ѡ����");
		cbFun.addItem("f(x)=x[0,10]");
		cbFun.addItem("f(x)=x*x+y*y[-10,10]");
		upPanel.add(this.instructionLabel,BorderLayout.NORTH);
		centerPanel.add(cbFun);
		labPopulationNum =new JLabel("��Ⱥ��ģ:");
		SpinnerNumberModel modelPN = new SpinnerNumberModel(20,20,200,1);
		//JSpinner�ɵ����ڣ���ʼֵ20����Сֵ20�����ֵ200������1��
		spinPopulationNum = new JSpinner(modelPN);
		spinPopulationNum.setSize(5,5);
		labCrossP=new JLabel("�������:");
		SpinnerNumberModel modelCP = new SpinnerNumberModel(0.8,0.6,1.0,0.1);
		spinCrossP= new JSpinner(modelCP);
		labGenovariationP=new JLabel("�������:");
		SpinnerNumberModel modelGP = new SpinnerNumberModel(0.005,0.005,0.01,0.001);
		spinGenovariationP= new JSpinner(modelGP);
		labPrecision = new JLabel("Ҫ�󾫶�λ��:");
		SpinnerNumberModel modelP = new SpinnerNumberModel(2,1,8,1);
		spinPrecision = new JSpinner(modelP);
		labIterateNum = new JLabel("����������");
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
//����ѡ��
	public JComboBox getCbFun() {
		return cbFun;
	}
	public void setCbFun(JComboBox cbFun) {
		this.cbFun = cbFun;
	}
	//��ʾ
	public JLabel getInstructionLabel() {
		return instructionLabel;
	}
	public void setInstructionLabel(JLabel instructionLabel) {
		this.instructionLabel = instructionLabel;
	}
	//�������
	public JSpinner getSpinCrossP() {
		return spinCrossP;
	}
	public void setSpinCrossP(JSpinner spinCrossP) {
		this.spinCrossP = spinCrossP;
	}
	//�������
	public JSpinner getSpinGenovariationP() {
		return spinGenovariationP;
	}
	public void setSpinGenovariationP(JSpinner spinGenovariationP) {
		this.spinGenovariationP = spinGenovariationP;
	}
	//��������
	public JSpinner getSpinIterateNum() {
		return spinIterateNum;
	}
	public void setSpinIterateNum(JSpinner spinIterateNum) {
		this.spinIterateNum = spinIterateNum;
	}
	//��Ⱥ��ģ
	public JSpinner getSpinPopulationNum() {
		return spinPopulationNum;
	}
	public void setSpinPopulationNum(JSpinner spinPopulationNum) {
		this.spinPopulationNum = spinPopulationNum;
	}
	//����
	public JSpinner getSpinPrecision() {
		return spinPrecision;
	}
	public void setSpinPrecision(JSpinner spinPrecision) {
		this.spinPrecision = spinPrecision;
	}
}
