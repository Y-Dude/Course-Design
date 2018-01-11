package 车辆租赁系统;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

import java.util.*;
public class L_rent {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
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
	   System.out.print("连接失败");}
	  try{
		  JFrame J1=new JFrame();
		  J1.setSize(500, 300);
		  J1.setTitle("可租用车辆信息查询");
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
		  
		  String[] columnNames={"车牌号","车辆类型","车辆名称","价格","购买时间","车辆状况","租金标准"}; //列名
		  rs=st.executeQuery(sql);
		  Object[][] rowData=new Object[count][7]; //表格数据
		  count=0;
		   while (rs.next()){ //遍历查询结果   
		    rowData[count][0]=rs.getString("carnum"); //初始化数组内容
		    rowData[count][1]=rs.getString("type");
		    rowData[count][2]=rs.getString("carname");
		    rowData[count][3]=rs.getString("price");
		    rowData[count][4]=rs.getString("buytime");
		    rowData[count][5]=rs.getString("status");
		    rowData[count][6]=rs.getString("rstandard");
		    count++;
		   }
		   JTable table=new JTable(rowData,columnNames); //实例化表格
		   J1.add(new JScrollPane(table));
		   J1.setVisible(true);
		   J1.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);//实现关闭子窗口而不关闭父窗口
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
			  String zu= JOptionPane.showInputDialog(this,"请输入要租用车辆的车牌号：",
		              "租用",JOptionPane.QUESTION_MESSAGE);//弹出信息对话框。
			  String zu2= JOptionPane.showInputDialog(this,"请输入今天日期：",
		              "确定",JOptionPane.QUESTION_MESSAGE);
			 try{
				  Class.forName(driverName);}
		   catch(ClassNotFoundException ex) {  }
		 try{
			 Con=DriverManager.getConnection(dbURL,userName,userPwd);//连接数据源。

			 prest=Con.prepareStatement("UPDATE [CarRent].[dbo].[carinfo] SET status='Y' WHERE Carnum=?");
			 prest.setString(1, zu);//设置第一个问号的取值
			 prest.executeUpdate();//更新数据。
			 prest=Con.prepareStatement("UPDATE [CarRent].[dbo].[rentinfo] SET leasedate=? WHERE Carnum=?");
			 prest.setString(1, zu2);
			 prest.setString(2, zu);
			 prest.executeUpdate();
			 JOptionPane.showMessageDialog(this,"已租用车牌号为"+zu+"的车辆！",
					 "租用",JOptionPane.INFORMATION_MESSAGE);//弹出操作成功的对话框。
			 Con.close();//关闭连接。
		 }
		 catch(SQLException ex) {  System.out.println(ex);   }
		  }
	  }
}