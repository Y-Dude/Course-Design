package 车辆租赁系统;

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
	Menu Carinfo,Rentinfo,返回;
	MenuItem Csearch,Crent;
	MenuItem Dsearch,Rsearch,Lrent,Creturn,Dequipped;
	MenuItem R;
	
	public InfoWindow2(){
		setLayout(new FlowLayout());
		setTitle("车辆租赁系统");
		
		
		mb = new MenuBar();
		Carinfo = new Menu("车俩信息");
		Rentinfo = new Menu("租赁信息");
		返回 = new Menu("返回");
		返回.addActionListener(this);
		
		Csearch = new MenuItem("车辆信息查询");
		Crent = new MenuItem("租赁车辆查询");
		Dsearch = new MenuItem("司机信息查询");
		Rsearch = new MenuItem("租赁信息查询");
		Lrent = new MenuItem("租车");
		Creturn = new MenuItem("还车");
		Dequipped = new MenuItem("司机配备");
		R = new MenuItem("返回登录窗口");
		
		Carinfo.add(Csearch);Csearch.addActionListener(this);
		Carinfo.add(Crent);Crent.addActionListener(this);
		
		Rentinfo.add(Dsearch);Dsearch.addActionListener(this);
		Rentinfo.add(Rsearch);Rsearch.addActionListener(this);
		Rentinfo.add(Lrent);Lrent.addActionListener(this);
		Rentinfo.add(Creturn);Creturn.addActionListener(this);
		Rentinfo.add(Dequipped);Dequipped.addActionListener(this);
		
		返回.add(R);R.addActionListener(this);
		
		mb.add(Carinfo);mb.add(Rentinfo);mb.add(返回);
		setMenuBar(mb);
		
        t.append("\n\n\n");
        t.append("               =============================================\n");
        t.append("               ==                                         ==\n");
        t.append("               ==           欢迎使用车辆租赁系统          ==\n");
        t.append("               ==                                         ==\n");
        t.append("               ==                           客户版        ==\n");
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

