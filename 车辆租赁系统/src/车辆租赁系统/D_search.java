package ��������ϵͳ;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;

public class D_search {
	public static void main(String[] args) {
		// TODO �Զ����ɵķ������

	}
}
class search3 extends JFrame{
	  String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
	  String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=CarRent";
	  String userName="sa";
	  String userPwd="123456";
	  Connection Con;
	  Statement st;
	  String sql;
	  ResultSet rs;
	  search3(){
	  try{
		  Class.forName(driverName);}
	  catch(ClassNotFoundException e)
	  {
	   e.printStackTrace();
	   System.out.print("����ʧ��");}
	  try{
		  JFrame J1=new JFrame();
		  J1.setSize(500, 300);
		  J1.setTitle("˾����Ϣ��ѯ");
		  
		  Con=DriverManager.getConnection(dbURL,userName,userPwd);
		  st=Con.createStatement();
		  sql="SELECT* FROM [CarRent].[dbo].[driver]";
		  rs=st.executeQuery(sql);
		  int count=0;
		  while(rs.next()){
			  count++;
		  }
		  
		  String[] columnNames={"���֤��","����","�Ա�","��������","��ַ","�绰","��ʻ֤��"}; //����
		  rs=st.executeQuery(sql);
		  Object[][] rowData=new Object[count][7]; //�������
		  count=0;
		   while (rs.next()){ //������ѯ���   
		    rowData[count][0]=rs.getString("Didcard"); //��ʼ����������
		    rowData[count][1]=rs.getString("dname");
		    rowData[count][2]=rs.getString("sex");
		    rowData[count][3]=rs.getString("birth");
		    rowData[count][4]=rs.getString("addr");
		    rowData[count][5]=rs.getString("phone");
		    rowData[count][6]=rs.getString("license");
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