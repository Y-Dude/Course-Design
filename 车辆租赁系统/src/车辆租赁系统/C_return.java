package ��������ϵͳ;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTable;

public class C_return {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������

	}

}
class return1 extends JFrame implements ActionListener{
	
	String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
	  String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=CarRent";
	  String userName="sa";
	  String userPwd="123456";
	  Connection Con;
	  Statement st;
	  String sql;
	  ResultSet rs;
	  return1(){
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
		  JButton button=new JButton("Return");
		  J1.add(button);
		  button.setBounds(400,220,75,25);
		  button.addActionListener(this);
		  
		  Con=DriverManager.getConnection(dbURL,userName,userPwd);
		  st=Con.createStatement();
		  sql="SELECT [CarRent].[dbo].[rentinfo].*  FROM [CarRent].[dbo].[carinfo],[CarRent].[dbo].[rentinfo] WHERE [carinfo].carnum=[rentinfo].carnum AND status='Y' ";
		  rs=st.executeQuery(sql);
		  int count=0;
		  while(rs.next()){
			  count++;
		  }
		  
		  String[] columnNames={"���ƺ�","���֤��","˾������","��𵥼�","��������","��������"}; //����
		  rs=st.executeQuery(sql);
		  Object[][] rowData=new Object[count][6]; //�������
		  count=0;
		   while (rs.next()){ //������ѯ���   
		    rowData[count][0]=rs.getString("carnum"); //��ʼ����������
		    rowData[count][1]=rs.getString("idcard");
		    rowData[count][2]=rs.getString("dname");
		    rowData[count][3]=rs.getString("rstandard");
		    rowData[count][4]=rs.getString("leasedate");
		    rowData[count][5]=rs.getString("returndate");
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
		  String d1=null;
			 String d2=null;
			 String d3=null;
		  if (e.getActionCommand()=="Return"){
			  String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
			  String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=CarRent";
			  String userName="sa";
			  String userPwd="123456";
			  Connection Con;
			  Statement st;
			  String sql;
			  ResultSet rs;
			  PreparedStatement prest;
			  String huan= JOptionPane.showInputDialog(this,"������Ҫ�������ĳ��ƺţ�",
		              "����",JOptionPane.QUESTION_MESSAGE);//������Ϣ�Ի���
			  String huan2= JOptionPane.showInputDialog(this,"������������ڣ�",
		              "ȷ��",JOptionPane.QUESTION_MESSAGE);
			 try{
				  Class.forName(driverName);}
		   catch(ClassNotFoundException ex) {  }
		 try{
			 Con=DriverManager.getConnection(dbURL,userName,userPwd);//��������Դ��

			 prest=Con.prepareStatement("UPDATE [CarRent].[dbo].[carinfo] SET status='N' WHERE Carnum=?");
			 prest.setString(1, huan);//���õ�һ���ʺŵ�ȡֵ
			 prest.executeUpdate();//�������ݡ�
			 prest=Con.prepareStatement("UPDATE [CarRent].[dbo].[rentinfo] SET returndate=? WHERE Carnum=?");
			 prest.setString(1, huan2);
			 prest.setString(2, huan);
			 prest.executeUpdate();
			 
			 prest=Con.prepareStatement("SELECT rstandard,leasedate,returndate "
			       		+ "FROM [CarRent].[dbo].[rentinfo] WHERE carnum= ?");
			 prest.setString(1,huan);
			 rs=prest.executeQuery();
			 while(rs.next()){
				 d3=rs.getString(1);
			 d1=rs.getString(2);
			 d2=rs.getString(3);
			 }
			 Between b= new Between(d1,d2,d3);
			 JOptionPane.showMessageDialog(this,"���ƺ�Ϊ"+huan+"�ĳ����ѹ黹��",
					 "����",JOptionPane.INFORMATION_MESSAGE);//���������ɹ��ĶԻ���
			 Con.close();//�ر����ӡ�
		 }
		 catch(SQLException ex) {  System.out.println(ex);   }
		  }
	  }
}