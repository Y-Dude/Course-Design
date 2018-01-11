package 车辆租赁系统;

import java.awt.Button;
import java.awt.Choice;
import java.awt.Dialog;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Label;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class Register {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根

	}

}


class Reg extends Dialog implements ActionListener//录入界面。
{
	 TextField 昵称,用户名,密码;
	 JPanel p;
	 Choice choice;
	 Button 确定,取消;
	 
	 Reg(Entry entry,String s)
	 {
	   super(entry,s);
	   昵称=new TextField(20);
	   用户名=new TextField(20);
	   密码=new TextField(20);   
	   choice=new Choice();//新建名为"choice"的下拉列表。
	   
	   setLayout(new FlowLayout(FlowLayout.LEFT));
	   add(new Label("昵称    ："));
	   add(昵称);
	   add(new Label("用户名："));
	   add(用户名);
	   add(new Label("密码    ："));
	   add(密码);
	   add(new Label("用户类型："));		   
	   choice.add("客户");choice.add("司机");//在组合框中添加选择
	   add(choice);//添加组合框
	   确定=new Button("确定");
	   取消=new Button("取消");
	   确定.addActionListener(this);
	   取消.addActionListener(this);
	   p = new JPanel();
	   p.add(确定);
	   p.add(取消);
	   add(p);
	   setBounds(200,200,280,400);
	   setTitle("注册");
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
          String c1=昵称.getText();//获取“车牌号”文本框内输入的信息。
          String c2=用户名.getText();
          String c3=密码.getText();
          String c4=choice.getSelectedItem();
           //获取“choice”下拉列表选择的信息。
           if(c1.length()>0 && c2.length()>0&& c3.length()>0)
               //判断前三个文本框内是否输入了信息。
             {//若文本框内有信息时，新建一个对象。
 			   try{
 				 Con=DriverManager.getConnection(dbURL,userName,userPwd);
 			         //连接数据源
               prest=Con.prepareStatement("INSERT INTO [CarRent].[dbo].[user] VALUES(?,?,?,?)");
               //预处理-插入。
               prest.setString(1,c1);
               prest.setString(2,c2);
               prest.setString(3,c3);
               prest.setString(4,c4);
               //给？赋值。
               prest.executeUpdate();//更新数据。
 		        Con.close();//关闭连接。	
 		        JOptionPane.showMessageDialog(this,"注册成功！",
 		 		  	              "OK",JOptionPane.INFORMATION_MESSAGE);//弹出成功对话框。
 				      }
 				       catch(SQLException ex) {  System.out.println(e);   }
 				        昵称.setText("");//把文本框内容清空，以便下次输入。
					   	用户名.setText("");
			            密码.setText("");

 			   }
 		  else { /*当文本框内没有输入信息时，则会弹出一个“警告”窗口，上面显示“请输入信息！”。*/
 		       JOptionPane.showMessageDialog(this,"请输入信息！","Warning",
 		    		   JOptionPane.WARNING_MESSAGE);}}
	      else//“取消”按钮。
	    {  dispose();}
	 }
}
