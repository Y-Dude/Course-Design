package ��������ϵͳ;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
public class U_delete {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������

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
		 String no= JOptionPane.showInputDialog(this,"�����뽫Ҫɾ���û����û��ţ�",
	              "ɾ��",JOptionPane.QUESTION_MESSAGE);//������Ϣ�Ի���
		 try{
			  Class.forName(driverName);}
	   catch(ClassNotFoundException e) {  }
	 try{
		 Con=DriverManager.getConnection(dbURL,userName,userPwd);//��������Դ��

		 prest=Con.prepareStatement("DELETE FROM [CarRent].[dbo].[user] WHERE unum=?");//Ԥ����-ɾ����
		 prest.setString(1, no);//���õ�һ���ʺŵ�ȡֵ
		 prest.executeUpdate();//�������ݡ�
		 
		 JOptionPane.showMessageDialog(this,"�û���Ϊ"+no+"���û���¼��ɾ����",
				 "ɾ��",JOptionPane.INFORMATION_MESSAGE);//���������ɹ��ĶԻ���
		 Con.close();//�ر����ӡ�
	 }
	 catch(SQLException ex) {  System.out.println(ex);   }
	 }
}

