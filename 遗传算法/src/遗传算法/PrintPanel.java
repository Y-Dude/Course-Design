package �Ŵ��㷨;

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
		this.textarea.setLineWrap (false);//����Ϊ��ֹ�Զ�����,��ʼֵΪfalse.
		this.textarea.setForeground (Color.black);//������ɫ
		scrollPane = new JScrollPane(this.textarea);
		this.clearButton = new JButton("���");
		this.exeButton = new JButton("����");
		ButtonGroup typeshow = new ButtonGroup();
		this.rbmidetail = new JRadioButtonMenuItem("��ʾ");
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

