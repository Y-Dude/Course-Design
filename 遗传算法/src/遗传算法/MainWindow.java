package 遗传算法;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MainWindow extends WindowAdapter implements ActionListener{
	private static final int MAXHEIGHT = 700,MAXWIDTH = 800;
	private MainMenuBar  mainMenuBar;
	private InputPanel inputPanel ;
	private PrintPanel printPanel ;
	private int funID;
	private char codeID;
	private int selectionID;
	private int crossID;
	private int genovariationID;
	private int populationNum;
	private int iterateNum ;
	private int showStyle;
	private double pc; //cross 0.6~1.0
	private double pv ; //variation 0.005~0.01 
	private int precision;
	public MainWindow(){		
		JFrame jfr = new JFrame("GA");
		jfr.setSize(MAXWIDTH, MAXHEIGHT);
		jfr.setLocation(60, 0);
		Container contentpane = jfr.getContentPane();
		contentpane.setLayout(new BorderLayout());
		mainMenuBar = new MainMenuBar();
		jfr.setJMenuBar(mainMenuBar);
		JPanel upPanel = new JPanel();
		upPanel.setLayout(new BorderLayout());
		inputPanel = new InputPanel();
		printPanel = new PrintPanel();
		mainMenuBar.getMiExit().addActionListener(this);
		inputPanel.getCbFun().addActionListener(this);
		printPanel.getExeButton().addActionListener(this);
		contentpane.add(inputPanel,BorderLayout.NORTH);
		contentpane.add(printPanel,BorderLayout.CENTER);
		jfr.setVisible(true);
		jfr.addWindowListener(this);
	}
	public void actionPerformed(ActionEvent e){
		if(e.getSource()==mainMenuBar.getMiExit()){
			System.exit(0);
		}
		else if(e.getSource()==printPanel.getExeButton()){
			this.populationNum = Integer.valueOf(inputPanel.getSpinPopulationNum().getValue().toString()).intValue();
			this.pc = Double.parseDouble(inputPanel.getSpinCrossP().getValue().toString());
			this.pv = Double.parseDouble(inputPanel.getSpinGenovariationP().getValue().toString());
			this.precision = Integer.valueOf(inputPanel.getSpinPrecision().getValue().toString()).intValue();
			this.iterateNum = Integer.valueOf(inputPanel.getSpinIterateNum().getValue().toString()).intValue();
			if(mainMenuBar.getRbmiBinaryCode().isSelected()){
				this.codeID = 'b';
			}

			if(mainMenuBar.getRbmiOnepointcrossover().isSelected()){
				this.crossID = 1;
			}
			if(mainMenuBar.getRbmiPoint().isSelected()){
				this.genovariationID = 1;
			}
			if(printPanel.getRbmidetail().isSelected()){
				showStyle=2;
			}
			this.funID = inputPanel.getCbFun().getSelectedIndex();
			if(this.funID==0){
				JOptionPane.showMessageDialog(null,"请选择要评估函数");
				inputPanel.getCbFun().setFocusable(true);
			}
			else{
				
				  new Thread(new Runnable() {
				        public void run()
				        {
				        	Function ef = new Function(funID,codeID,precision);
							Population population = new Population(populationNum,iterateNum,selectionID,crossID,genovariationID,pc,pv,ef,showStyle);
							Gene[] gene = population.getGenes();
							printPanel.clear();
							printPanel.append("-------------------------------------------------------------------------【初始种群】--------------------------------------------------------------------------------\n");
							printPanel.append(population.getSbInitGenes().toString());
							printPanel.append("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~-~~-【最后一代种群】-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
							printPanel.append(ef.getSbLastGenes(showStyle, gene).toString());
							printPanel.append(ef.getSbBestGeneetail(population).toString());
				        }
				    }).start();
			}
		}
	}
	
	public void windowClosing(WindowEvent e){
		System.exit(0);		
	}
	public static void main(String[] args) {
		new MainWindow();
	}

}
