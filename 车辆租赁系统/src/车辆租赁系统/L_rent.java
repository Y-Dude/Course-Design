package ��������ϵͳ;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

import java.util.*;
public class L_rent {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
	}
}

class rent2 extends JFrame implements ActionListener{
	
	String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
	  String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=CarRent";
	  String userName="sa";
	  String userPwd="123456";
	  Connection Con;
	  Statement st;
	  String sql;
	  ResultSet rs;
	  rent2(){
	  try{
		  Class.forName(driverName);}
	  catch(ClassNotFoundException e)
	  {
	   e.printStackTrace();
	   System.out.print("����ʧ��");}
	  try{
		  JFrame J1=new JFrame();
		  J1.setSize(500, 300);
		  J1.setTitle("�����ó�����Ϣ��ѯ");
		  JButton button=new JButton("Rent");
		  J1.add(button);
		  button.setBounds(410,220,65,25);
		  button.addActionListener(this);
		  
		  Con=DriverManager.getConnection(dbURL,userName,userPwd);
		  st=Con.createStatement();
		  sql="SELECT* FROM [CarRent].[dbo].[carinfo] WHERE status='N' ";
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
	  
	  public void actionPerformed(ActionEvent e){
		  if (e.getActionCommand()=="Rent"){
			  String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
			  String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=CarRent";
			  String userName="sa";
			  String userPwd="123456";
			  Connection Con;
			  Statement st;
			  String sql;
			  ResultSet rs;
			  PreparedStatement prest;
			  String zu= JOptionPane.showInputDialog(this,"������Ҫ���ó����ĳ��ƺţ�",
		              "����",JOptionPane.QUESTION_MESSAGE);//������Ϣ�Ի���
			  String zu2= JOptionPane.showInputDialog(this,"������������ڣ�",
		              "ȷ��",JOptionPane.QUESTION_MESSAGE);
			 try{
				  Class.forName(driverName);}
		   catch(ClassNotFoundException ex) {  }
		 try{
			 Con=DriverManager.getConnection(dbURL,userName,userPwd);//��������Դ��

			 prest=Con.prepareStatement("UPDATE [CarRent].[dbo].[carinfo] SET status='Y' WHERE Carnum=?");
			 prest.setString(1, zu);//���õ�һ���ʺŵ�ȡֵ
			 prest.executeUpdate();//�������ݡ�
			 prest=Con.prepareStatement("UPDATE [CarRent].[dbo].[rentinfo] SET leasedate=? WHERE Carnum=?");
			 prest.setString(1, zu2);
			 prest.setString(2, zu);
			 prest.executeUpdate();
			 JOptionPane.showMessageDialog(this,"�����ó��ƺ�Ϊ"+zu+"�ĳ�����",
					 "����",JOptionPane.INFORMATION_MESSAGE);//���������ɹ��ĶԻ���
			 Con.close();//�ر����ӡ�
		 }
		 catch(SQLException ex) {  System.out.println(ex);   }
		  }
	  }
}