package 车辆租赁系统;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class Main {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根

		Entry en=new Entry();
	}

}
class Entry extends JFrame implements ActionListener//录入界面。
{
	 TextField 用户名,密码;
	 JPanel p;
	 Choice choice;
	 Button 登录,注册;
	 
	 Entry()
	 {
	   用户名=new TextField(30);
	   密码=new TextField(30);
	   密码.setEchoChar('$');   //设置符号使密码不可见
	   
	   choice=new Choice();//新建名为"choice"的下拉列表。
	   
	   setLayout(new FlowLayout(FlowLayout.LEFT));
	   add(new Label("用户名    ："));
	   add(用户名);
	   add(new Label("密码        ："));
	   add(密码);
	   setTitle("登录");

	   add(new Label("用户类别  ：                     "));		   
	   choice.add("客户");choice.add("司机");
	   choice.add("管理员");//在组合框中添加选择
	   add(choice);//添加组合框
	   登录=new Button("登录");
	   注册=new Button("注册");
	   登录.addActionListener(this);
	   注册.addActionListener(this);
	   p = new JPanel();
	   p.add(登录);
	   p.add(注册);
	   add(p);
	   setBounds(500,200,400,200);
	   setVisible(true);
	 }
	 
	 
	 public void actionPerformed(ActionEvent e)
	 {
		  String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
		  String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=CarRent";
		  String userName="sa";
		  String userPwd="123456";
		  Connection Con;
		  Statement st;
		  ResultSet  rs;
		  PreparedStatement prest;
		  try{
			  Class.forName(driverName);}
	   catch(ClassNotFoundException ex) {  }
	    if (e.getSource()==登录)//执行登录操作。
	    {
	    	boolean flag=false;
          String c1=用户名.getText();//获取文本框内输入的信息。
          String c2=密码.getText();
          String c3=choice.getSelectedItem();
           //获取“choice”下拉列表选择的信息。
           if(c1.length()>0 && c2.length()>0&& c3.length()>0)
               //判断前三个文本框内是否输入了信息。
             {//若文本框内有信息时，新建一个对象。
 			   try{
 				 Con=DriverManager.getConnection(dbURL,userName,userPwd);
 			         //连接数据源
               prest=Con.prepareStatement("SELECT unum,passw,type FROM [CarRent].[dbo].[user]");
               rs=prest.executeQuery();
               
               while(rs.next()){
            	   if(c1.equals(rs.getString(1))&&c2.equals(rs.getString(2))&&c3.equals(rs.getString(3)))
            	   {
            		   flag=true;
            		   break;
            	   }
               }
               if(flag){
            	   if(c3=="管理员"){
            		   dispose();
            	   InfoWindow win= new InfoWindow();}
            	   if(c3=="客户"){
            		   dispose();
            		InfoWindow2 win2= new InfoWindow2();
            	   }
            	   if(c3=="司机"){
            		   dispose();
            		 InfoWindow2 win2= new InfoWindow2();
            	   }
               }
               else{
            	   JOptionPane.showMessageDialog(this,"用户名,密码或身份错误","Warning",
     		    		   JOptionPane.WARNING_MESSAGE);
               }
               Con.close();//关闭连接。
               	
 				      }
 				       catch(SQLException ex) {  System.out.println(e);  }
 			   }
 		  else { /*当文本框内没有输入信息时，则会弹出一个“警告”窗口，上面显示“请输入信息！”。*/
 		       JOptionPane.showMessageDialog(this,"请输入信息！","Warning",
 		    		   JOptionPane.WARNING_MESSAGE);}
           }
	      if(e.getSource()==注册){
	    	  Reg r=new Reg(this,"注册");
	    	  }//注册按钮
	    }
	 }