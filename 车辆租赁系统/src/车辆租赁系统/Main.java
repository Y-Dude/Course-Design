package ��������ϵͳ;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class Main {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������

		Entry en=new Entry();
	}

}
class Entry extends JFrame implements ActionListener//¼����档
{
	 TextField �û���,����;
	 JPanel p;
	 Choice choice;
	 Button ��¼,ע��;
	 
	 Entry()
	 {
	   �û���=new TextField(30);
	   ����=new TextField(30);
	   ����.setEchoChar('$');   //���÷���ʹ���벻�ɼ�
	   
	   choice=new Choice();//�½���Ϊ"choice"�������б�
	   
	   setLayout(new FlowLayout(FlowLayout.LEFT));
	   add(new Label("�û���    ��"));
	   add(�û���);
	   add(new Label("����        ��"));
	   add(����);
	   setTitle("��¼");

	   add(new Label("�û����  ��                     "));		   
	   choice.add("�ͻ�");choice.add("˾��");
	   choice.add("����Ա");//����Ͽ������ѡ��
	   add(choice);//�����Ͽ�
	   ��¼=new Button("��¼");
	   ע��=new Button("ע��");
	   ��¼.addActionListener(this);
	   ע��.addActionListener(this);
	   p = new JPanel();
	   p.add(��¼);
	   p.add(ע��);
	   add(p);
	   setBounds(500,200,400,200);
	   setVisible(true);
	 }
	 
	 
	 public void actionPerformed(ActionEvent e)
	 {
		  String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
		  String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=CarRent";
		  String userName="sa";
		  String userPwd="123456";
		  Connection Con;
		  Statement st;
		  ResultSet  rs;
		  PreparedStatement prest;
		  try{
			  Class.forName(driverName);}
	   catch(ClassNotFoundException ex) {  }
	    if (e.getSource()==��¼)//ִ�е�¼������
	    {
	    	boolean flag=false;
          String c1=�û���.getText();//��ȡ�ı������������Ϣ��
          String c2=����.getText();
          String c3=choice.getSelectedItem();
           //��ȡ��choice�������б�ѡ�����Ϣ��
           if(c1.length()>0 && c2.length()>0&& c3.length()>0)
               //�ж�ǰ�����ı������Ƿ���������Ϣ��
             {//���ı���������Ϣʱ���½�һ������
 			   try{
 				 Con=DriverManager.getConnection(dbURL,userName,userPwd);
 			         //��������Դ
               prest=Con.prepareStatement("SELECT unum,passw,type FROM [CarRent].[dbo].[user]");
               rs=prest.executeQuery();
               
               while(rs.next()){
            	   if(c1.equals(rs.getString(1))&&c2.equals(rs.getString(2))&&c3.equals(rs.getString(3)))
            	   {
            		   flag=true;
            		   break;
            	   }
               }
               if(flag){
            	   if(c3=="����Ա"){
            		   dispose();
            	   InfoWindow win= new InfoWindow();}
            	   if(c3=="�ͻ�"){
            		   dispose();
            		InfoWindow2 win2= new InfoWindow2();
            	   }
            	   if(c3=="˾��"){
            		   dispose();
            		 InfoWindow2 win2= new InfoWindow2();
            	   }
               }
               else{
            	   JOptionPane.showMessageDialog(this,"�û���,�������ݴ���","Warning",
     		    		   JOptionPane.WARNING_MESSAGE);
               }
               Con.close();//�ر����ӡ�
               	
 				      }
 				       catch(SQLException ex) {  System.out.println(e);  }
 			   }
 		  else { /*���ı�����û��������Ϣʱ����ᵯ��һ�������桱���ڣ�������ʾ����������Ϣ������*/
 		       JOptionPane.showMessageDialog(this,"��������Ϣ��","Warning",
 		    		   JOptionPane.WARNING_MESSAGE);}
           }
	      if(e.getSource()==ע��){
	    	  Reg r=new Reg(this,"ע��");
	    	  }//ע�ᰴť
	    }
	 }