package ��������ϵͳ;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

import java.util.*;

public class CarRent {
	public static void main(String args[]){
		InfoWindow win= new InfoWindow();
	}
}

class InfoWindow extends JFrame	implements ActionListener{
	TextArea t = new TextArea(12,68);;
	MenuBar mb;
	Menu Carinfo,Rentinfo,Userinfo,����;
	MenuItem Csearch,Cadd,Cchange,Cdelete,Crent;
	MenuItem Lsearch,Dsearch,Rsearch,Dequipped;
	MenuItem Usearch,Udelete;
	MenuItem R;
	
	public InfoWindow(){
		setLayout(new FlowLayout());
		setTitle("��������ϵͳ");
		
		mb = new MenuBar();
		Carinfo = new Menu("������Ϣ");
		Rentinfo = new Menu("������Ϣ");
		Userinfo = new Menu("�û���Ϣ");
		���� = new Menu("����");
		����.addActionListener(this);
		
		Csearch = new MenuItem("������Ϣ��ѯ");
		Cadd = new MenuItem("������Ϣ���");
		Cchange = new MenuItem("������Ϣ�޸�");
		Cdelete = new MenuItem("������Ϣɾ��");
		Crent = new MenuItem("���޳�����ѯ");
		Lsearch = new MenuItem("�ͻ���Ϣ��ѯ");
		Dsearch = new MenuItem("˾����Ϣ��ѯ");
		Rsearch = new MenuItem("������Ϣ��ѯ");

		Dequipped = new MenuItem("˾���䱸");
		Usearch = new MenuItem("�û���Ϣ��ѯ");
		Udelete = new MenuItem("�û���Ϣɾ��");
		
		R = new MenuItem("���ص�¼����");
		
		Carinfo.add(Csearch);Csearch.addActionListener(this);
		Carinfo.add(Cadd);Cadd.addActionListener(this);
		Carinfo.add(Cchange);Cchange.addActionListener(this);
		Carinfo.add(Cdelete);Cdelete.addActionListener(this);
		Carinfo.add(Crent);Crent.addActionListener(this);
		
		Rentinfo.add(Lsearch);Lsearch.addActionListener(this);
		Rentinfo.add(Dsearch);Dsearch.addActionListener(this);
		Rentinfo.add(Rsearch);Rsearch.addActionListener(this);
		Rentinfo.add(Dequipped);Dequipped.addActionListener(this);
		
		Userinfo.add(Usearch);Usearch.addActionListener(this);
		Userinfo.add(Udelete);Udelete.addActionListener(this);
		
		����.add(R);R.addActionListener(this);
		
		
		mb.add(Carinfo);mb.add(Rentinfo);mb.add(Userinfo);mb.add(����);
		setMenuBar(mb);
		
        t.append("\n\n\n");
        t.append("               =============================================\n");
        t.append("               ==                                         ==\n");
        t.append("               ==           ��ӭʹ�ó�������ϵͳ          ==\n");
        t.append("               ==                                         ==\n");
        t.append("               ==                          ����Ա��       ==\n");
        t.append("               ==                                    YKP  ==\n");
        t.append("               =============================================\n");
        add(t);
        
		
		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){System.exit(0);}});
		setVisible(true);
		setBounds(400,200,520,300);
	}//infowindow
	
	
	public void actionPerformed(ActionEvent e){
		  if(e.getSource()==Csearch){
			  
			  search srch=new search();
			  
		  }//������Ϣ��ѯ
		  
		  if(e.getSource()==Cadd){
			  
			  LDialog dia=new LDialog(this,"Cadd");
			  
		  }//������Ϣ���
		  
		  if(e.getSource()==Cchange){
			  CDialog dia=new CDialog(this,"Cchange");
		  }//������Ϣ�޸�
		  
		  if(e.getSource()==Cdelete){
			  delete del = new delete();
		  }//������Ϣɾ��
		  
		  if(e.getSource()==Crent){
			  rent1 ren = new rent1();
		  }
		  if(e.getSource()==Lsearch){
			  search2 srch2=new search2();
		  }
		  if(e.getSource()==Dsearch){
			  search3 srch3=new search3();
		  }
		  if(e.getSource()==Dequipped){
			  
			  equipped equ=new equipped();
		  }

		  if(e.getSource()==Rsearch){
			  
			  search4 srch4= new search4();
		  }
		  if(e.getSource()==Usearch){
			  
			  search5 srch5= new search5();
		  }

		  if(e.getSource()==Udelete){
			  
			  delete2 del2= new delete2();
		  }
		  if(e.getSource()==R){
			  
			  Entry en= new Entry();
			  dispose();
		  }
		  
		  
}//actionperformed
	
	
	
	
	
}//carrent
