package �Ŵ��㷨;

import javax.swing.ButtonGroup;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JRadioButtonMenuItem;

public class MainMenuBar extends JMenuBar{
	private static final long serialVersionUID = 1L;
	private JMenu menuFile= new JMenu();
	private JMenu menuCodeType = new JMenu();
	private JMenu menuSelection= new JMenu();
	private JMenu menuCross = new JMenu();
	private JMenu menuGenovariation = new JMenu();
	private JMenu menuHelp = new JMenu();
	private JRadioButtonMenuItem rbmiBinaryCode= new JRadioButtonMenuItem();
	private JRadioButtonMenuItem rbmiRoulette = new JRadioButtonMenuItem();
	private JRadioButtonMenuItem rbmiOnepointcrossover = new JRadioButtonMenuItem();
	private JRadioButtonMenuItem rbmiPoint = new JRadioButtonMenuItem();
	private JMenuItem miExit = new JMenuItem();
	public MainMenuBar() {
		this.menuFile.setText("�ļ�");
		this.menuCodeType.setText("����");
		this.menuSelection.setText("ѡ��");
		this.menuCross.setText("����");
		this.menuGenovariation.setText("����");
		this.menuHelp.setText("����");
		this.miExit.setText("�˳�");
		this.rbmiBinaryCode.setText("�����Ʊ���");
		this.rbmiBinaryCode.setSelected(true);
		this.rbmiRoulette.setText("����ѡ��");
		this.rbmiRoulette.setSelected(true);
		this.rbmiOnepointcrossover.setText("���㽻��");
		this.rbmiOnepointcrossover.setSelected(true);
		this.rbmiPoint.setText("�����");
		this.rbmiPoint.setSelected(true);
		this.menuFile.add(this.miExit);
		ButtonGroup typeCode = new ButtonGroup();
		typeCode.add(rbmiBinaryCode);
		ButtonGroup typeSelection = new ButtonGroup();
		typeSelection.add(rbmiRoulette);
		ButtonGroup typeCross = new ButtonGroup();
		typeCross.add(rbmiOnepointcrossover);
		ButtonGroup typeGenovariation= new ButtonGroup();
		typeGenovariation.add(rbmiPoint);
		this.menuCodeType.add(rbmiBinaryCode);
		this.menuSelection.add(rbmiRoulette);
		this.menuCross.add(rbmiOnepointcrossover);
		this.menuGenovariation.add(rbmiPoint);
		this.add(this.menuFile);
		this.add(this.menuCodeType);
		this.add(this.menuSelection);;
		this.add(this.menuCross);
		this.add(this.menuGenovariation);
	}
	//����
	public JMenu getMenuCross() {
		return menuCross;
	}
	public void setMenuCross(JMenu menuCross) {
		this.menuCross = menuCross;
	}
	//�ļ�
	public JMenu getMenuFile() {
		return menuFile;
	}
	public void setMenuFile(JMenu menuFile) {
		this.menuFile = menuFile;
	}
	//����
	public JMenu getMenuGenovariation() {
		return menuGenovariation;
	}
	public void setMenuGenovariation(JMenu menuGenovariation) {
		this.menuGenovariation = menuGenovariation;
	}
	//ѡ��
	public JMenu getMenuSelection() {
		return menuSelection;
	}
	public void setMenuSelection(JMenu menuSelection) {
		this.menuSelection = menuSelection;
	}
	//�˳�
	public JMenuItem getMiExit() {
		return miExit;
	}
	public void setMiExit(JMenuItem miExit) {
		this.miExit = miExit;
	}
//���㽻��
	public JRadioButtonMenuItem getRbmiOnepointcrossover() {
		return rbmiOnepointcrossover;
	}
	public void setRbmiOnepointcrossover(JRadioButtonMenuItem rbmiOnepointcrossover) {
		this.rbmiOnepointcrossover = rbmiOnepointcrossover;
	}
	//�����
	public JRadioButtonMenuItem getRbmiPoint() {
		return rbmiPoint;
	}
	public void setRbmiPoint(JRadioButtonMenuItem rbmiPoint) {
		this.rbmiPoint = rbmiPoint;
	}
	//����ѡ��
	public JRadioButtonMenuItem getRbmiRoulette() {
		return rbmiRoulette;
	}
	public void setRbmiRoulette(JRadioButtonMenuItem rbmiRoulette) {
		this.rbmiRoulette = rbmiRoulette;
	}
	//�����Ʊ���
	public JRadioButtonMenuItem getRbmiBinaryCode() {
		return rbmiBinaryCode;
	}
	public void setRbmiBinaryCode(JRadioButtonMenuItem rbmiBinaryCode) {
		this.rbmiBinaryCode = rbmiBinaryCode;
	}
//����
	public JMenu getMenuCodeType() {
		return menuCodeType;
	}
	public void setMenuCodeType(JMenu menuCodeType) {
		this.menuCodeType = menuCodeType;
	}
}
