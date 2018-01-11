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

public class D_equipped {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根

	}

}
class equipped extends JFrame implements ActionListener{
	
	String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
	  String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=CarRent";
	  String userName="sa";
	  String userPwd="123456";
	  Connection Con;
	  Statement st;
	  String sql;
	  ResultSet rs;
	  equipped(){
	  try{
		  Class.forName(driverName);}
	  catch(ClassNotFoundException e)
	  {
	   e.printStackTrace();
	   System.out.print("连接失败");}
	  try{
		  JFrame J1=new JFrame();
		  J1.setSize(500, 300);
		  J1.setTitle("司机信息");
		  JButton button=new JButton("Equip");
		  J1.add(button);
		  button.setBounds(410,220,65,25);
		  button.addActionListener(this);
		  
		  Con=DriverManager.getConnection(dbURL,userName,userPwd);
		  st=Con.createStatement();
		  sql="SELECT* FROM [CarRent].[dbo].[driver]";
		  rs=st.executeQuery(sql);
		  int count=0;
		  while(rs.next()){
			  count++;
		  }
		  
		  String[] columnNames={"身份证号","司机姓名","性别","生日","住址","电话","驾驶证号"}; //列名
		  rs=st.executeQuery(sql);
		  Object[][] rowData=new Object[count][7]; //表格数据
		  count=0;
		   while (rs.next()){ //遍历查询结果   
		    rowData[count][0]=rs.getString("Didcard"); //初始化数组内容
		    rowData[count][1]=rs.getString("dname");
		    rowData[count][2]=rs.getString("sex");
		    rowData[count][3]=rs.getString("birth");
		    rowData[count][4]=rs.getString("addr");
		    rowData[count][5]=rs.getString("phone");
		    rowData[count][6]=rs.getString("license");
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
		  if (e.getActionCommand()=="Equip"){
			  String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
			  String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=CarRent";
			  String userName="sa";
			  String userPwd="123456";
			  Connection Con;
			  Statement st;
			  String sql;
			  ResultSet rs;
			  PreparedStatement prest;
			  String eup= JOptionPane.showInputDialog(this,"请输入要配置司机车辆的车牌号：",
		              "确定",JOptionPane.QUESTION_MESSAGE);//弹出信息对话框。
			  String eup2= JOptionPane.showInputDialog(this,"请输入要配置的司机姓名：",
		              "确定",JOptionPane.QUESTION_MESSAGE);
			 try{
				  Class.forName(driverName);}
		   catch(ClassNotFoundException ex) {  }
		 try{
			 Con=DriverManager.getConnection(dbURL,userName,userPwd);//连接数据源。

			 prest=Con.prepareStatement("UPDATE [CarRent].[dbo].[rentinfo] SET dname=? WHERE carnum=?");
			 prest.setString(1, eup2);//设置第一个问号的取值
			 prest.setString(2, eup);
			 prest.executeUpdate();//更新数据。
			 JOptionPane.showMessageDialog(this,"配置成功",
					 "配置",JOptionPane.INFORMATION_MESSAGE);//弹出操作成功的对话框。
			 Con.close();//关闭连接。
		 }
		 catch(SQLException ex) {  System.out.println(ex);   }
		  }
	  }
}