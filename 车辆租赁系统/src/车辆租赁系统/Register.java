package ��������ϵͳ;

import java.awt.Button;
import java.awt.Choice;
import java.awt.Dialog;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Label;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class Register {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������

	}

}


class Reg extends Dialog implements ActionListener//¼����档
{
	 TextField �ǳ�,�û���,����;
	 JPanel p;
	 Choice choice;
	 Button ȷ��,ȡ��;
	 
	 Reg(Entry entry,String s)
	 {
	   super(entry,s);
	   �ǳ�=new TextField(20);
	   �û���=new TextField(20);
	   ����=new TextField(20);   
	   choice=new Choice();//�½���Ϊ"choice"�������б�
	   
	   setLayout(new FlowLayout(FlowLayout.LEFT));
	   add(new Label("�ǳ�    ��"));
	   add(�ǳ�);
	   add(new Label("�û�����"));
	   add(�û���);
	   add(new Label("����    ��"));
	   add(����);
	   add(new Label("�û����ͣ�"));		   
	   choice.add("�ͻ�");choice.add("˾��");//����Ͽ������ѡ��
	   add(choice);//�����Ͽ�
	   ȷ��=new Button("ȷ��");
	   ȡ��=new Button("ȡ��");
	   ȷ��.addActionListener(this);
	   ȡ��.addActionListener(this);
	   p = new JPanel();
	   p.add(ȷ��);
	   p.add(ȡ��);
	   add(p);
	   setBounds(200,200,280,400);
	   setTitle("ע��");
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
          String c1=�ǳ�.getText();//��ȡ�����ƺš��ı������������Ϣ��
          String c2=�û���.getText();
          String c3=����.getText();
          String c4=choice.getSelectedItem();
           //��ȡ��choice�������б�ѡ�����Ϣ��
           if(c1.length()>0 && c2.length()>0&& c3.length()>0)
               //�ж�ǰ�����ı������Ƿ���������Ϣ��
             {//���ı���������Ϣʱ���½�һ������
 			   try{
 				 Con=DriverManager.getConnection(dbURL,userName,userPwd);
 			         //��������Դ
               prest=Con.prepareStatement("INSERT INTO [CarRent].[dbo].[user] VALUES(?,?,?,?)");
               //Ԥ����-���롣
               prest.setString(1,c1);
               prest.setString(2,c2);
               prest.setString(3,c3);
               prest.setString(4,c4);
               //������ֵ��
               prest.executeUpdate();//�������ݡ�
 		        Con.close();//�ر����ӡ�	
 		        JOptionPane.showMessageDialog(this,"ע��ɹ���",
 		 		  	              "OK",JOptionPane.INFORMATION_MESSAGE);//�����ɹ��Ի���
 				      }
 				       catch(SQLException ex) {  System.out.println(e);   }
 				        �ǳ�.setText("");//���ı���������գ��Ա��´����롣
					   	�û���.setText("");
			            ����.setText("");

 			   }
 		  else { /*���ı�����û��������Ϣʱ����ᵯ��һ�������桱���ڣ�������ʾ����������Ϣ������*/
 		       JOptionPane.showMessageDialog(this,"��������Ϣ��","Warning",
 		    		   JOptionPane.WARNING_MESSAGE);}}
	      else//��ȡ������ť��
	    {  dispose();}
	 }
}
