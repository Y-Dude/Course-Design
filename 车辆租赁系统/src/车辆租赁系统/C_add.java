package ��������ϵͳ;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class C_add {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������

	}
}

	class LDialog extends Dialog implements ActionListener//¼����档
	 {
		 TextField ���ƺ�,��������,��������,�۸�,����ʱ��,����״��,����׼;
		 JPanel p;
		 Choice choice;
		 Button ȷ��,ȡ��;
		 
		 LDialog(Frame f,String s)
		 {
		   super(f,s);
		   ���ƺ�=new TextField(20);
		   ��������=new TextField(20);
		   ��������=new TextField(20);
		   �۸�=new TextField(20);
		   ����ʱ��=new TextField(20);
		   ����׼=new TextField(20);
		   
		   choice=new Choice();//�½���Ϊ"choice"�������б�
		   
		   setLayout(new FlowLayout(FlowLayout.LEFT));
		   add(new Label("���ƺ�    ��"));
		   add(���ƺ�);
		   add(new Label("�������ͣ�"));
		   add(��������);
		   add(new Label("�������ƣ�"));
		   add(��������);
		   add(new Label("�۸�       �� "));
		   add(�۸�);
		   add(new Label("����ʱ�䣺"));
		   add(����ʱ��);
		   add(new Label("����״����                                 "));		   
		   choice.add("Y");choice.add("N");//����Ͽ������ѡ��
		   add(choice);//�����Ͽ�
		   add(new Label("����׼��"));add(����׼);
		   ȷ��=new Button("ȷ��");
		   ȡ��=new Button("ȡ��");
		   ȷ��.addActionListener(this);
		   ȡ��.addActionListener(this);
		   p = new JPanel();
		   p.add(ȷ��);
		   p.add(ȡ��);
		   add(p);
		   setBounds(200,200,280,400);
		   setTitle("���");
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
			  Statement st;
			  PreparedStatement prest;
			  try{
				  Class.forName(driverName);}
		   catch(ClassNotFoundException ex) {  }
		    if (e.getSource()==ȷ��)//ִ��ȷ��������
		    {
	           String c1=���ƺ�.getText();//��ȡ�����ƺš��ı������������Ϣ��
	           String c2=��������.getText();
	           String c3=��������.getText();
	           String c4=�۸�.getText();
	           String c5=����ʱ��.getText();
	           String c6=choice.getSelectedItem();
	            //��ȡ��choice�������б�ѡ�����Ϣ��
	           String c7=����׼.getText();
	            if(c1.length()>0 && c2.length()>0&& c3.length()>0)
	                //�ж�ǰ�����ı������Ƿ���������Ϣ��
	              {//���ı���������Ϣʱ���½�һ������
	  			   try{
	  				 Con=DriverManager.getConnection(dbURL,userName,userPwd);
	  			         //��������Դ
	                prest=Con.prepareStatement("INSERT INTO [CarRent].[dbo].[carinfo] VALUES(?,?,?,?,?,?,?)");
	                //Ԥ����-���롣
	                prest.setString(1,c1);
	                prest.setString(2,c2);
	                prest.setString(3,c3);
	                prest.setString(4,c4);
	                prest.setString(5,c5);
	                prest.setString(6,c6);
	                prest.setString(7,c7);
	                //������ֵ��
	                prest.executeUpdate();//�������ݡ�
	  		        Con.close();//�ر����ӡ�	
	  		        JOptionPane.showMessageDialog(this,"��Ϣ¼��ɹ���",
	  		 		  	              "OK",JOptionPane.INFORMATION_MESSAGE);//�����ɹ��Ի���
	  				      }
	  				       catch(SQLException ex) {  System.out.println(e);   }
	  				        ���ƺ�.setText("");//���ı���������գ��Ա��´����롣
						   	��������.setText("");
				            ��������.setText("");
				            �۸�.setText("");
				            ����ʱ��.setText("");
				            ����׼.setText("");
	  			   }
	  		  else { /*���ı�����û��������Ϣʱ����ᵯ��һ�������桱���ڣ�������ʾ����������Ϣ������*/
	  		       JOptionPane.showMessageDialog(this,"��������Ϣ��","Warning",
	  		    		   JOptionPane.WARNING_MESSAGE);}}
		      else//��ȡ������ť��
		    {  dispose();}
		 }
	}
	
