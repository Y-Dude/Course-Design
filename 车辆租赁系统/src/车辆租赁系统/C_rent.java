package ��������ϵͳ;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class C_rent {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
	}
}

class rent1 extends JFrame{
	
	String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
	  String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=CarRent";
	  String userName="sa";
	  String userPwd="123456";
	  Connection Con;
	  Statement st;
	  String sql;
	  ResultSet rs;
	  rent1(){
	  try{
		  Class.forName(driverName);}
	  catch(ClassNotFoundException e)
	  {
	   e.printStackTrace();
	   System.out.print("����ʧ��");}
	  try{
		  JFrame J1=new JFrame();
		  J1.setSize(500, 300);
		  J1.setTitle("���⳵����Ϣ��ѯ");
		  
		  Con=DriverManager.getConnection(dbURL,userName,userPwd);
		  st=Con.createStatement();
		  sql="SELECT* FROM [CarRent].[dbo].[carinfo] WHERE status='Y' ";
		  rs=st.executeQuery(sql);
		  int count=0;
		  while(rs.next()){
			  count++;
		  }
		  
		  String[] columnNames={"���ƺ�","��������","��������","�۸�","����ʱ��","����״��","����׼"}; //����
		  rs=st.executeQuery(sql);
		  Object[][] rowData=new Object[count][7]; //�������
		  count=0;
		   while (rs.next()){ //������ѯ���   
		    rowData[count][0]=rs.getString("carnum"); //��ʼ����������
		    rowData[count][1]=rs.getString("type");
		    rowData[count][2]=rs.getString("carname");
		    rowData[count][3]=rs.getString("price");
		    rowData[count][4]=rs.getString("buytime");
		    rowData[count][5]=rs.getString("status");
		    rowData[count][6]=rs.getString("rstandard");
		    count++;
		   }
		   JTable table=new JTable(rowData,columnNames); //ʵ�������
		   J1.add(new JScrollPane(table));
		   J1.setVisible(true);
		   J1.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);//ʵ�ֹر��Ӵ��ڶ����رո�����
		   Con.close();
	}catch(SQLException ex){ex.printStackTrace();}

	  }
}