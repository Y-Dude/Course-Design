package 车辆租赁系统;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class C_rent {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
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
	   System.out.print("连接失败");}
	  try{
		  JFrame J1=new JFrame();
		  J1.setSize(500, 300);
		  J1.setTitle("已租车辆信息查询");
		  
		  Con=DriverManager.getConnection(dbURL,userName,userPwd);
		  st=Con.createStatement();
		  sql="SELECT* FROM [CarRent].[dbo].[carinfo] WHERE status='Y' ";
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
}