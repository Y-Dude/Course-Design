package 车辆租赁系统;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;

public class R_search {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根

	}

}
class search4 extends JFrame{
	  String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
	  String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=CarRent";
	  String userName="sa";
	  String userPwd="123456";
	  Connection Con;
	  Statement st;
	  String sql;
	  ResultSet rs;
	  search4(){
	  try{
		  Class.forName(driverName);}
	  catch(ClassNotFoundException e)
	  {
	   e.printStackTrace();
	   System.out.print("连接失败");}
	  try{
		  JFrame J1=new JFrame();
		  J1.setSize(500, 300);
		  J1.setTitle("租赁信息查询");
		  
		  Con=DriverManager.getConnection(dbURL,userName,userPwd);
		  st=Con.createStatement();
		  sql="SELECT [CarRent].[dbo].[rentinfo].* FROM [CarRent].[dbo].[rentinfo],[CarRent].[dbo].[carinfo] WHERE [rentinfo].carnum=[carinfo].carnum AND [carinfo].status='Y' ";
		  rs=st.executeQuery(sql);
		  int count=0;
		  while(rs.next()){
			  count++;
		  }
		  
		  String[] columnNames={"车牌号","客户身份证","司机姓名","租金单价","起租日期","退租日期"}; //列名
		  rs=st.executeQuery(sql);
		  Object[][] rowData=new Object[count][6]; //表格数据
		  count=0;
		   while (rs.next()){ //遍历查询结果   
		    rowData[count][0]=rs.getString("carnum"); //初始化数组内容
		    rowData[count][1]=rs.getString("idcard");
		    rowData[count][2]=rs.getString("dname");
		    rowData[count][3]=rs.getString("rstandard");
		    rowData[count][4]=rs.getString("leasedate");
		    rowData[count][5]=rs.getString("returndate");
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