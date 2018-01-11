package 车辆租赁系统;

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
	Menu Carinfo,Rentinfo,Userinfo,返回;
	MenuItem Csearch,Cadd,Cchange,Cdelete,Crent;
	MenuItem Lsearch,Dsearch,Rsearch,Dequipped;
	MenuItem Usearch,Udelete;
	MenuItem R;
	
	public InfoWindow(){
		setLayout(new FlowLayout());
		setTitle("车辆租赁系统");
		
		mb = new MenuBar();
		Carinfo = new Menu("车俩信息");
		Rentinfo = new Menu("租赁信息");
		Userinfo = new Menu("用户信息");
		返回 = new Menu("返回");
		返回.addActionListener(this);
		
		Csearch = new MenuItem("车辆信息查询");
		Cadd = new MenuItem("车辆信息添加");
		Cchange = new MenuItem("车辆信息修改");
		Cdelete = new MenuItem("车辆信息删除");
		Crent = new MenuItem("租赁车辆查询");
		Lsearch = new MenuItem("客户信息查询");
		Dsearch = new MenuItem("司机信息查询");
		Rsearch = new MenuItem("租赁信息查询");

		Dequipped = new MenuItem("司机配备");
		Usearch = new MenuItem("用户信息查询");
		Udelete = new MenuItem("用户信息删除");
		
		R = new MenuItem("返回登录窗口");
		
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
		
		返回.add(R);R.addActionListener(this);
		
		
		mb.add(Carinfo);mb.add(Rentinfo);mb.add(Userinfo);mb.add(返回);
		setMenuBar(mb);
		
        t.append("\n\n\n");
        t.append("               =============================================\n");
        t.append("               ==                                         ==\n");
        t.append("               ==           欢迎使用车辆租赁系统          ==\n");
        t.append("               ==                                         ==\n");
        t.append("               ==                          管理员版       ==\n");
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
			  
		  }//车辆信息查询
		  
		  if(e.getSource()==Cadd){
			  
			  LDialog dia=new LDialog(this,"Cadd");
			  
		  }//车辆信息添加
		  
		  if(e.getSource()==Cchange){
			  CDialog dia=new CDialog(this,"Cchange");
		  }//车辆信息修改
		  
		  if(e.getSource()==Cdelete){
			  delete del = new delete();
		  }//车辆信息删除
		  
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
