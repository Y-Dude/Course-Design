package 遗传算法;

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
		this.menuFile.setText("文件");
		this.menuCodeType.setText("编码");
		this.menuSelection.setText("选择");
		this.menuCross.setText("交叉");
		this.menuGenovariation.setText("变异");
		this.menuHelp.setText("帮助");
		this.miExit.setText("退出");
		this.rbmiBinaryCode.setText("二进制编码");
		this.rbmiBinaryCode.setSelected(true);
		this.rbmiRoulette.setText("赌轮选择法");
		this.rbmiRoulette.setSelected(true);
		this.rbmiOnepointcrossover.setText("单点交叉");
		this.rbmiOnepointcrossover.setSelected(true);
		this.rbmiPoint.setText("点变异");
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
	//交叉
	public JMenu getMenuCross() {
		return menuCross;
	}
	public void setMenuCross(JMenu menuCross) {
		this.menuCross = menuCross;
	}
	//文件
	public JMenu getMenuFile() {
		return menuFile;
	}
	public void setMenuFile(JMenu menuFile) {
		this.menuFile = menuFile;
	}
	//变异
	public JMenu getMenuGenovariation() {
		return menuGenovariation;
	}
	public void setMenuGenovariation(JMenu menuGenovariation) {
		this.menuGenovariation = menuGenovariation;
	}
	//选择
	public JMenu getMenuSelection() {
		return menuSelection;
	}
	public void setMenuSelection(JMenu menuSelection) {
		this.menuSelection = menuSelection;
	}
	//退出
	public JMenuItem getMiExit() {
		return miExit;
	}
	public void setMiExit(JMenuItem miExit) {
		this.miExit = miExit;
	}
//单点交叉
	public JRadioButtonMenuItem getRbmiOnepointcrossover() {
		return rbmiOnepointcrossover;
	}
	public void setRbmiOnepointcrossover(JRadioButtonMenuItem rbmiOnepointcrossover) {
		this.rbmiOnepointcrossover = rbmiOnepointcrossover;
	}
	//点变异
	public JRadioButtonMenuItem getRbmiPoint() {
		return rbmiPoint;
	}
	public void setRbmiPoint(JRadioButtonMenuItem rbmiPoint) {
		this.rbmiPoint = rbmiPoint;
	}
	//赌轮选择法
	public JRadioButtonMenuItem getRbmiRoulette() {
		return rbmiRoulette;
	}
	public void setRbmiRoulette(JRadioButtonMenuItem rbmiRoulette) {
		this.rbmiRoulette = rbmiRoulette;
	}
	//二进制编码
	public JRadioButtonMenuItem getRbmiBinaryCode() {
		return rbmiBinaryCode;
	}
	public void setRbmiBinaryCode(JRadioButtonMenuItem rbmiBinaryCode) {
		this.rbmiBinaryCode = rbmiBinaryCode;
	}
//编码
	public JMenu getMenuCodeType() {
		return menuCodeType;
	}
	public void setMenuCodeType(JMenu menuCodeType) {
		this.menuCodeType = menuCodeType;
	}
}
