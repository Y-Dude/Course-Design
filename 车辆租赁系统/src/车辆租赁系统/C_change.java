package ��������ϵͳ;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

import java.util.*;

public class C_change {
	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
	}
}

class CDialog extends Dialog implements ActionListener{
	TextField ���ƺ�,��������,��������,�۸�,����ʱ��,����״��,����׼;
	 Button ȷ��,ȡ��;
	 CDialog(Frame f,String s)
	 {
	   super(f,s);
	   ���ƺ�=new TextField(20);
	   ��������=new TextField(20);
	   ��������=new TextField(20);
	   �۸�=new TextField(20);
	   ����ʱ��=new TextField(20);
	   ����״��=new TextField(20);
	   ����׼=new TextField(20);
	   ȷ��=new Button("ȷ��");
	   ȡ��=new Button("ȡ��");
	   ȷ��.addActionListener(this);
	   ȡ��.addActionListener(this);
      ���ƺ�.addActionListener(this);
      //ע���������
	   setLayout(new FlowLayout(FlowLayout.LEFT));//���ò��֡�
	   add(new Label("���ƺ�    ��"));
	   add(���ƺ�);
	   add(new Label("�������ͣ�"));
	   add(��������);
	   add(new Label("�������ƣ�"));
	   add(��������);
	   add(new Label("�۸�        ��"));
	   add(�۸�);
	   add(new Label("����ʱ�䣺"));
	   add(����ʱ��);
	   add(new Label("����״����"));
	   add(����״��);
	   add(new Label("����׼��"));
	   add(����׼);
	   add(ȷ��);
	   add(ȡ��);
	   //��Ӹ��������
	   setBounds(200,200,280,400);
	   setTitle("�޸�");
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
			  Class.forName(driverName);//������������
			  }
	   catch(ClassNotFoundException ex) {  }
      if(e.getSource()==���ƺ�)//�ڳ��ƺ��ı������س���ִ�е�����Զ���ʾ������Ϣ
      {
		  try{
			  Con=DriverManager.getConnection(dbURL,userName,userPwd);//��������Դ��
		       prest1=Con.prepareStatement("SELECT type,carname,price,buytime,status,rstandard "
		       		+ "FROM [CarRent].[dbo].[carinfo] WHERE carnum= ?");//Ԥ����-������ѯ��
		         prest1.setString(1,���ƺ�.getText());//���ã���ֵ��
		         rs=prest1.executeQuery();//���ؽ������
		         while (rs.next())
		         {
					 ��������.setText(rs.getString(1));
					 ��������.setText(rs.getString(2));
					 �۸�.setText(rs.getString(3));
					 ����ʱ��.setText(rs.getString(4));
					 ����״��.setText(rs.getString(5));
					 ����׼.setText(rs.getString(6));
					 }
				 Con.close();//�ر����ӡ�
		       }
		   catch(SQLException ex) {  System.out.println(e); }
	   }
	   else if (e.getSource()==ȷ��)//ִ��ȷ��
	    {
          String c1=���ƺ�.getText().trim();
          String c2=��������.getText().trim();
          String c3=��������.getText().trim();
          String c4=�۸�.getText().trim();
          String c5=����ʱ��.getText().trim();
          String c6=����״��.getText().trim();
          String c7=����׼.getText().trim();
          
          //��ȡ�ı������ֵ��
           if(c1.length()>0 && c2.length()>0&& c3.length()>0&&c4.length()>0&&c5.length()>0)
               //�ж��ı������Ƿ���������Ϣ��
               {  try
			   		 {
			   		   Class.forName(driverName);//������������
			   		  }
			   	   catch(java.lang.ClassNotFoundException ec){
			   			    ec.printStackTrace(); }
			   		 try
			   			{
			   			Con=DriverManager.getConnection(dbURL,userName,userPwd);
			   			    //��������Դ��
			   			prest2=Con.prepareStatement("update [CarRent].[dbo].[carinfo]"
			   				+ " set type=?,carname=?,price=?,buytime=?,status=?,rstandard=? WHERE carnum= ?");
							//Ԥ����-���¡�
		                    prest2.setString(1,c2);
		                    prest2.setString(2,c3);
		                    prest2.setString(3,c4);
		                    prest2.setString(4,c5);
		                    prest2.setString(5,c6);
		                    prest2.setString(6,c7);
		                    prest2.setString(7,c1);
							prest2.executeUpdate();
							 prest2.close();
			                 Con.close();//�ر����ӡ�
        JOptionPane.showMessageDialog(this,"��Ϣ�޸ĳɹ���","OK",JOptionPane.INFORMATION_MESSAGE);
			   }catch(SQLException ex)//������Ϣ��
			   {
			    ex.printStackTrace();
			    System.out.println("����1");
			   }
 			    }
 		  else { /*���ı�����û��������Ϣʱ����ᵯ��һ�������桱���ڣ�������ʾ����������Ϣ������*/
 			       JOptionPane.showMessageDialog(this,"��������Ϣ��","Warning",
 		                                         JOptionPane.WARNING_MESSAGE);
		       }
		}
	     else if (e.getSource()==ȡ��)//ִ��ȡ����ť��������ʧ��
	    {  dispose();}
	 }

	
}
