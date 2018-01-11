package 绘制x的平方图像;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import javax.swing.JFrame;
import javax.swing.JPanel;

	public class X_X {
		
		public static void main(String[] args) 
		{
			DrawFrame f=new DrawFrame();
			f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			f.setVisible(true);
		}
	}
	
	class DrawFrame extends JFrame{
	   public DrawFrame()
	   {
	      setTitle("函数X*X图像");
	      setSize(400,400);
	      setLocationRelativeTo(null);

	      // 将图贴入框中

	      DrawPanel panel = new DrawPanel();
	      add(panel);
	   }
	}

	class DrawPanel extends JPanel{
	   public void paintComponent(Graphics g)
	   {
	      super.paintComponent(g);
	      Graphics2D g2 = (Graphics2D)g;
	      
	      int x0=0;int y0=0;
	      int minx=-150;int maxx=150;
	      int miny=-150;int maxy=150;
	      
	      g2.translate(200,200);
	      g2.draw(new Line2D.Double(minx,y0,maxx,y0));
	      g2.draw(new Line2D.Double(maxx,y0,maxx-1,y0-1));
	      g2.draw(new Line2D.Double(maxx,y0,maxx-1,y0+1));
	      g2.drawString("x",151,0);
	      g2.draw(new Line2D.Double(x0,miny,x0,maxy));
	      g2.draw(new Line2D.Double(x0,miny,x0-1,miny+1));
	      g2.draw(new Line2D.Double(x0,miny,x0+1,miny+1));
	      g2.drawString("y",0,-150);
	      g2.drawString("y=x*x",75,-100);
	      
	      int[] arrayy=new int[200];
	      int[] arrayx=new int[200];
		  arrayx[0]=-100;
		  for (int i=0;i<199;i++)
		  {
		  	  arrayx[i+1]=arrayx[0]+i;
		  }
		  for (int i=0;i<200;i++)
		  {
		  	  arrayy[i]=-(arrayx[i]*arrayx[i])/10;
		  }
		  
		  g2.drawPolyline(arrayx,arrayy,200);
		  
	   }
}
