package 车辆租赁系统;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

import java.util.*;

public class C_change {
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
	}
}

class CDialog extends Dialog implements ActionListener{
	TextField 车牌号,车辆类型,车辆名称,价格,购买时间,车辆状况,租金标准;
	 Button 确定,取消;
	 CDialog(Frame f,String s)
	 {
	   super(f,s);
	   车牌号=new TextField(20);
	   车辆类型=new TextField(20);
	   车辆名称=new TextField(20);
	   价格=new TextField(20);
	   购买时间=new TextField(20);
	   车辆状况=new TextField(20);
	   租金标准=new TextField(20);
	   确定=new Button("确定");
	   取消=new Button("取消");
	   确定.addActionListener(this);
	   取消.addActionListener(this);
      车牌号.addActionListener(this);
      //注册监听器。
	   setLayout(new FlowLayout(FlowLayout.LEFT));//设置布局。
	   add(new Label("车牌号    ："));
	   add(车牌号);
	   add(new Label("车辆类型："));
	   add(车辆类型);
	   add(new Label("车辆名称："));
	   add(车辆名称);
	   add(new Label("价格        ："));
	   add(价格);
	   add(new Label("购买时间："));
	   add(购买时间);
	   add(new Label("车辆状况："));
	   add(车辆状况);
	   add(new Label("租金标准："));
	   add(租金标准);
	   add(确定);
	   add(取消);
	   //添加各种组件。
	   setBounds(200,200,280,400);
	   setTitle("修改");
	   setVisible(true);
	   addWindowListener(new WindowAdapter()
	                   {   public void windowClosing(WindowEvent e){
	                       dispose();}});
	 }
	 public void actionPerformed(ActionEvent e)
	 {
		String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
		String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=CarRent";
		String userName="sa";
		String userPwd="123456";
        Connection Con;
		ResultSet  rs;
		PreparedStatement prest1,prest2;
		try{
			  Class.forName(driverName);//加载驱动器。
			  }
	   catch(ClassNotFoundException ex) {  }
      if(e.getSource()==车牌号)//在车牌号文本区按回车所执行的命令。自动显示其他信息
      {
		  try{
			  Con=DriverManager.getConnection(dbURL,userName,userPwd);//连接数据源。
		       prest1=Con.prepareStatement("SELECT type,carname,price,buytime,status,rstandard "
		       		+ "FROM [CarRent].[dbo].[carinfo] WHERE carnum= ?");//预处理-条件查询。
		         prest1.setString(1,车牌号.getText());//设置？的值。
		         rs=prest1.executeQuery();//返回结果集。
		         while (rs.next())
		         {
					 车辆类型.setText(rs.getString(1));
					 车辆名称.setText(rs.getString(2));
					 价格.setText(rs.getString(3));
					 购买时间.setText(rs.getString(4));
					 车辆状况.setText(rs.getString(5));
					 租金标准.setText(rs.getString(6));
					 }
				 Con.close();//关闭连接。
		       }
		   catch(SQLException ex) {  System.out.println(e); }
	   }
	   else if (e.getSource()==确定)//执行确定
	    {
          String c1=车牌号.getText().trim();
          String c2=车辆类型.getText().trim();
          String c3=车辆名称.getText().trim();
          String c4=价格.getText().trim();
          String c5=购买时间.getText().trim();
          String c6=车辆状况.getText().trim();
          String c7=租金标准.getText().trim();
          
          //获取文本框里的值。
           if(c1.length()>0 && c2.length()>0&& c3.length()>0&&c4.length()>0&&c5.length()>0)
               //判断文本框内是否输入了信息。
               {  try
			   		 {
			   		   Class.forName(driverName);//加载驱动器。
			   		  }
			   	   catch(java.lang.ClassNotFoundException ec){
			   			    ec.printStackTrace(); }
			   		 try
			   			{
			   			Con=DriverManager.getConnection(dbURL,userName,userPwd);
			   			    //连接数据源。
			   			prest2=Con.prepareStatement("update [CarRent].[dbo].[carinfo]"
			   				+ " set type=?,carname=?,price=?,buytime=?,status=?,rstandard=? WHERE carnum= ?");
							//预处理-更新。
		                    prest2.setString(1,c2);
		                    prest2.setString(2,c3);
		                    prest2.setString(3,c4);
		                    prest2.setString(4,c5);
		                    prest2.setString(5,c6);
		                    prest2.setString(6,c7);
		                    prest2.setString(7,c1);
							prest2.executeUpdate();
							 prest2.close();
			                 Con.close();//关闭连接。
        JOptionPane.showMessageDialog(this,"信息修改成功！","OK",JOptionPane.INFORMATION_MESSAGE);
			   }catch(SQLException ex)//弹出信息框。
			   {
			    ex.printStackTrace();
			    System.out.println("错误1");
			   }
 			    }
 		  else { /*当文本框内没有输入信息时，则会弹出一个“警告”窗口，上面显示“请输入信息！”。*/
 			       JOptionPane.showMessageDialog(this,"请输入信息！","Warning",
 		                                         JOptionPane.WARNING_MESSAGE);
		       }
		}
	     else if (e.getSource()==取消)//执行取消按钮，窗口消失。
	    {  dispose();}
	 }

	
}
