package ��������ϵͳ;

import java.awt.FlowLayout;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.awt.TextArea;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;

public class CarRent2 {
	public static void main(String args[]){
		InfoWindow2 win= new InfoWindow2();
	}
}

class InfoWindow2 extends JFrame	implements ActionListener{
	TextArea t = new TextArea(12,68);;
	MenuBar mb;
	Menu Carinfo,Rentinfo,����;
	MenuItem Csearch,Crent;
	MenuItem Dsearch,Rsearch,Lrent,Creturn,Dequipped;
	MenuItem R;
	
	public InfoWindow2(){
		setLayout(new FlowLayout());
		setTitle("��������ϵͳ");
		
		
		mb = new MenuBar();
		Carinfo = new Menu("������Ϣ");
		Rentinfo = new Menu("������Ϣ");
		���� = new Menu("����");
		����.addActionListener(this);
		
		Csearch = new MenuItem("������Ϣ��ѯ");
		Crent = new MenuItem("���޳�����ѯ");
		Dsearch = new MenuItem("˾����Ϣ��ѯ");
		Rsearch = new MenuItem("������Ϣ��ѯ");
		Lrent = new MenuItem("�⳵");
		Creturn = new MenuItem("����");
		Dequipped = new MenuItem("˾���䱸");
		R = new MenuItem("���ص�¼����");
		
		Carinfo.add(Csearch);Csearch.addActionListener(this);
		Carinfo.add(Crent);Crent.addActionListener(this);
		
		Rentinfo.add(Dsearch);Dsearch.addActionListener(this);
		Rentinfo.add(Rsearch);Rsearch.addActionListener(this);
		Rentinfo.add(Lrent);Lrent.addActionListener(this);
		Rentinfo.add(Creturn);Creturn.addActionListener(this);
		Rentinfo.add(Dequipped);Dequipped.addActionListener(this);
		
		����.add(R);R.addActionListener(this);
		
		mb.add(Carinfo);mb.add(Rentinfo);mb.add(����);
		setMenuBar(mb);
		
        t.append("\n\n\n");
        t.append("               =============================================\n");
        t.append("               ==                                         ==\n");
        t.append("               ==           ��ӭʹ�ó�������ϵͳ          ==\n");
        t.append("               ==                                         ==\n");
        t.append("               ==                           �ͻ���        ==\n");
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
		  
		  
		  
		  if(e.getSource()==Crent){
			  rent1 ren = new rent1();
		  }
	
		  if(e.getSource()==Dsearch){
			  search3 srch3=new search3();
		  }
		  if(e.getSource()==Lrent){
			  rent2 ren2=new rent2();
		  }
		  if(e.getSource()==Creturn){
			  return1 ret=new return1();
		  }
		  if(e.getSource()==Dequipped){
			  
			  equipped equ=new equipped();
		  }

		  if(e.getSource()==Rsearch){
			  
			  search4 srch4= new search4();
		  }


		  if(e.getSource()==R){
			  
			  Entry en= new Entry();
			  dispose();
		  }

		  
		  
}//actionperformed
	
	
	
	
	
}//carrent

