package 车辆租赁系统;

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
		// TODO 自动生成的方法存根

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
	   System.out.print("连接失败");}
	  try{
		  JFrame J1=new JFrame();
		  J1.setSize(500, 300);
		  J1.setTitle("被租用车辆信息查询");
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
		  
		  String[] columnNames={"车牌号","身份证号","司机姓名","租金单价","起租日期","退租日期"}; //列名
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
			  String huan= JOptionPane.showInputDialog(this,"请输入要还车辆的车牌号：",
		              "还车",JOptionPane.QUESTION_MESSAGE);//弹出信息对话框。
			  String huan2= JOptionPane.showInputDialog(this,"请输入今天日期：",
		              "确定",JOptionPane.QUESTION_MESSAGE);
			 try{
				  Class.forName(driverName);}
		   catch(ClassNotFoundException ex) {  }
		 try{
			 Con=DriverManager.getConnection(dbURL,userName,userPwd);//连接数据源。

			 prest=Con.prepareStatement("UPDATE [CarRent].[dbo].[carinfo] SET status='N' WHERE Carnum=?");
			 prest.setString(1, huan);//设置第一个问号的取值
			 prest.executeUpdate();//更新数据。
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
			 JOptionPane.showMessageDialog(this,"车牌号为"+huan+"的车辆已归还！",
					 "还车",JOptionPane.INFORMATION_MESSAGE);//弹出操作成功的对话框。
			 Con.close();//关闭连接。
		 }
		 catch(SQLException ex) {  System.out.println(ex);   }
		  }
	  }
}