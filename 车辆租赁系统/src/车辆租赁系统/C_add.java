package 车辆租赁系统;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class C_add {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根

	}
}

	class LDialog extends Dialog implements ActionListener//录入界面。
	 {
		 TextField 车牌号,车辆类型,车辆名称,价格,购买时间,车辆状况,租金标准;
		 JPanel p;
		 Choice choice;
		 Button 确定,取消;
		 
		 LDialog(Frame f,String s)
		 {
		   super(f,s);
		   车牌号=new TextField(20);
		   车辆类型=new TextField(20);
		   车辆名称=new TextField(20);
		   价格=new TextField(20);
		   购买时间=new TextField(20);
		   租金标准=new TextField(20);
		   
		   choice=new Choice();//新建名为"choice"的下拉列表。
		   
		   setLayout(new FlowLayout(FlowLayout.LEFT));
		   add(new Label("车牌号    ："));
		   add(车牌号);
		   add(new Label("车辆类型："));
		   add(车辆类型);
		   add(new Label("车辆名称："));
		   add(车辆名称);
		   add(new Label("价格       ： "));
		   add(价格);
		   add(new Label("购买时间："));
		   add(购买时间);
		   add(new Label("车辆状况：                                 "));		   
		   choice.add("Y");choice.add("N");//在组合框中添加选择
		   add(choice);//添加组合框
		   add(new Label("租金标准："));add(租金标准);
		   确定=new Button("确定");
		   取消=new Button("取消");
		   确定.addActionListener(this);
		   取消.addActionListener(this);
		   p = new JPanel();
		   p.add(确定);
		   p.add(取消);
		   add(p);
		   setBounds(200,200,280,400);
		   setTitle("添加");
		   setVisible(true);
		   addWindowListener(new WindowAdapter()
		                   {   public void windowClosing(WindowEvent e){
		                       dispose();}});
		 }
		 
		 
		 public void actionPerformed(ActionEvent e)
		 {
			  String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
			  String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=CarRent";
			  String userName="sa";
			  String userPwd="123456";
			  Connection Con;
			  Statement st;
			  PreparedStatement prest;
			  try{
				  Class.forName(driverName);}
		   catch(ClassNotFoundException ex) {  }
		    if (e.getSource()==确定)//执行确定操作。
		    {
	           String c1=车牌号.getText();//获取“车牌号”文本框内输入的信息。
	           String c2=车辆类型.getText();
	           String c3=车辆名称.getText();
	           String c4=价格.getText();
	           String c5=购买时间.getText();
	           String c6=choice.getSelectedItem();
	            //获取“choice”下拉列表选择的信息。
	           String c7=租金标准.getText();
	            if(c1.length()>0 && c2.length()>0&& c3.length()>0)
	                //判断前三个文本框内是否输入了信息。
	              {//若文本框内有信息时，新建一个对象。
	  			   try{
	  				 Con=DriverManager.getConnection(dbURL,userName,userPwd);
	  			         //连接数据源
	                prest=Con.prepareStatement("INSERT INTO [CarRent].[dbo].[carinfo] VALUES(?,?,?,?,?,?,?)");
	                //预处理-插入。
	                prest.setString(1,c1);
	                prest.setString(2,c2);
	                prest.setString(3,c3);
	                prest.setString(4,c4);
	                prest.setString(5,c5);
	                prest.setString(6,c6);
	                prest.setString(7,c7);
	                //给？赋值。
	                prest.executeUpdate();//更新数据。
	  		        Con.close();//关闭连接。	
	  		        JOptionPane.showMessageDialog(this,"信息录入成功！",
	  		 		  	              "OK",JOptionPane.INFORMATION_MESSAGE);//弹出成功对话框。
	  				      }
	  				       catch(SQLException ex) {  System.out.println(e);   }
	  				        车牌号.setText("");//把文本框内容清空，以便下次输入。
						   	车辆类型.setText("");
				            车辆名称.setText("");
				            价格.setText("");
				            购买时间.setText("");
				            租金标准.setText("");
	  			   }
	  		  else { /*当文本框内没有输入信息时，则会弹出一个“警告”窗口，上面显示“请输入信息！”。*/
	  		       JOptionPane.showMessageDialog(this,"请输入信息！","Warning",
	  		    		   JOptionPane.WARNING_MESSAGE);}}
		      else//“取消”按钮。
		    {  dispose();}
		 }
	}
	
