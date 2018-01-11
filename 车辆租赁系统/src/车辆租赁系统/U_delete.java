package 车辆租赁系统;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
public class U_delete {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根

	}

}


class delete2 extends JFrame{
	  String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
	  String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=CarRent";
	  String userName="sa";
	  String userPwd="123456";
	  Connection Con;
	  Statement st;
	  String sql;
	  ResultSet rs;
	  PreparedStatement prest;
	 
	 delete2(){
		 String no= JOptionPane.showInputDialog(this,"请输入将要删除用户的用户号：",
	              "删除",JOptionPane.QUESTION_MESSAGE);//弹出信息对话框。
		 try{
			  Class.forName(driverName);}
	   catch(ClassNotFoundException e) {  }
	 try{
		 Con=DriverManager.getConnection(dbURL,userName,userPwd);//连接数据源。

		 prest=Con.prepareStatement("DELETE FROM [CarRent].[dbo].[user] WHERE unum=?");//预处理-删除。
		 prest.setString(1, no);//设置第一个问号的取值
		 prest.executeUpdate();//更新数据。
		 
		 JOptionPane.showMessageDialog(this,"用户名为"+no+"的用户记录已删除！",
				 "删除",JOptionPane.INFORMATION_MESSAGE);//弹出操作成功的对话框。
		 Con.close();//关闭连接。
	 }
	 catch(SQLException ex) {  System.out.println(ex);   }
	 }
}

