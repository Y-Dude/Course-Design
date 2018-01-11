package 遗传算法;

import java.awt.*;
import java.io.*;
import java.util.*;
import java.awt.event.*;
import javax.swing.*;

public class PrintPanel extends JPanel implements ActionListener{
	private static final long serialVersionUID = 1L;
	private static final int MAXTEXTAREAROWS = 22,MAXTEXTAREACOLUMNS =68,MAXHEIGHT = 600,MAXWIDTH = 800;
	private JTextArea textarea;
	private JButton clearButton, exeButton;
	private JRadioButtonMenuItem rbmidetail;
	private JScrollPane scrollPane;
	public PrintPanel(){
		this.setSize(MAXWIDTH, MAXHEIGHT);
		JPanel upPanel = new JPanel();
		JPanel downPanel = new JPanel();
		JPanel centerPanel = new JPanel();
		upPanel.setLayout(new GridLayout(1,3));
		this.textarea = new JTextArea(MAXTEXTAREAROWS,MAXTEXTAREACOLUMNS);
		this.textarea.setLineWrap (false);//设置为禁止自动换行,初始值为false.
		this.textarea.setForeground (Color.black);//字体颜色
		scrollPane = new JScrollPane(this.textarea);
		this.clearButton = new JButton("清空");
		this.exeButton = new JButton("计算");
		ButtonGroup typeshow = new ButtonGroup();
		this.rbmidetail = new JRadioButtonMenuItem("显示");
		typeshow.add(rbmidetail);
		this.clearButton.addActionListener(this);
		this.exeButton.addActionListener(this);
		upPanel.add(this.rbmidetail);
		upPanel.add(this.exeButton);
		centerPanel.add(this.scrollPane);
		downPanel.add(this.clearButton);
		this.add(upPanel);
		this.add(centerPanel);
		this.add(downPanel);
	}
	public void append(String str){
		this.textarea.append(str);
	}
	public void clear(){
		this.textarea.setText(" ");
	}
	public void actionPerformed(ActionEvent e){
		if(e.getSource()==this.clearButton){
			this.textarea.setText("");
		}
	}
	public JRadioButtonMenuItem getRbmidetail() {
		return rbmidetail;
	}
	public void setRbmidetail(JRadioButtonMenuItem rbmidetail) {
		this.rbmidetail = rbmidetail;
	}
	public JButton getExeButton() {
		return exeButton;
	}
	public void setExeButton(JButton exeButton) {
		this.exeButton = exeButton;
	}
}

