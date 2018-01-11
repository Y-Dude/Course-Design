package 六边形旋转;

import javax.swing.JFrame;  
import javax.swing.JPanel;  
import java.awt.Graphics;  
import java.awt.Polygon;  
public class Around extends JFrame{  
  
	public class PolygonsPanel extends JPanel {  
		
	    protected void paintComponent(Graphics g)  
	    {  
	        super.paintComponent(g);  
	        int xCenter=getWidth()/2;     // getWidth()返回当前组建的最大宽度
	        int yCenter=getHeight()/2;    //getHeight()返回当前组建的最大高度
	        int radius=(int)(Math.min(getWidth(), getHeight()*0.4));  
	        Polygon polygon=new Polygon();
	        Polygon polygon2=new Polygon();
	        int x1=xCenter+radius,x2=(int)(xCenter+radius*Math.cos(2*Math.PI/6));
	        int x3=(int)(xCenter+radius*Math.cos(2*2*Math.PI/6)) ,x4=(int)(xCenter+radius*Math.cos(2*3*Math.PI/6)) ;
	        int x5=(int)(xCenter+radius*Math.cos(2*4*Math.PI/6)) ,x6=(int)(xCenter+radius*Math.cos(2*5*Math.PI/6)) ;
	        int y1=yCenter ,y2=(int)(yCenter-radius*Math.sin(2*Math.PI/6)) ;
	        int y3=(int)(yCenter-radius*Math.sin(2*2*Math.PI/6)),y4=(int)(yCenter-radius*Math.sin(2*3*Math.PI/6)) ;
	        int y5=(int)(yCenter-radius*Math.sin(2*4*Math.PI/6)),y6=(int)(yCenter-radius*Math.sin(2*5*Math.PI/6)) ;
	        polygon.addPoint(x1,y1);  
	        polygon.addPoint(x2,y2);  
	        polygon.addPoint(x3,y3);  
	        polygon.addPoint(x4,y4);  
	        polygon.addPoint(x5,y5);  
	        polygon.addPoint(x6,y6);
	        g.drawPolygon(polygon);
	       /* int xx1=(int)(x1*0.866-y1*0.5+1),yy1=(int)(x1*0.5-y1*0.866+1);
	        int xx2=(int)(x2*0.866-y2*0.5+1),yy2=(int)(x1*0.5-y2*0.866+1);
	        int xx3=(int)(x3*0.866-y3*0.5+1),yy3=(int)(x1*0.5-y3*0.866+1);
	        int xx4=(int)(x4*0.866-y4*0.5+1),yy4=(int)(x1*0.5-y4*0.866+1);
	        int xx5=(int)(x5*0.866-y5*0.5+1),yy5=(int)(x1*0.5-y5*0.866+1);
	        int xx6=(int)(x6*0.866-y6*0.5+1),yy6=(int)(x1*0.5-y6*0.866+1);*/
	        int xx1=(int)(x1*0.866+y1*05+1),yy1=(int)(x1*0.5-y1*0.866+1);
	        int xx2=(int)(x2*0.866+y2*05+1),yy2=(int)(x2*0.5-y2*0.866+1);
	        int xx3=(int)(x3*0.866+y3*05+1),yy3=(int)(x3*0.5-y3*0.866+1);
	        int xx4=(int)(x4*0.866+y4*05+1),yy4=(int)(x4*0.5-y4*0.866+1);
	        int xx5=(int)(x5*0.866+y5*05+1),yy5=(int)(x5*0.5-y5*0.866+1);
	        int xx6=(int)(x6*0.866+y6*05+1),yy6=(int)(x6*0.5-y6*0.866+1);
	        polygon2.addPoint(xx1,yy1);  
	        polygon2.addPoint(xx2,yy2);  
	        polygon2.addPoint(xx3,yy3);  
	        polygon2.addPoint(xx4,yy4);  
	        polygon2.addPoint(xx5,yy5);  
	        polygon2.addPoint(xx6,yy6);
	        g.fillPolygon(polygon2);  // drawPolygon()只画不填  fillPolygon()画并填充
	    }  
	}  
	
    public Around()  
    {  
        setTitle("DrawPolygon");  
        add(new PolygonsPanel());  
    }
    
    public static void main(String[] args)  
    {  
        Around frame =new Around();  
        frame.setSize(200,250);  
        frame.setLocationRelativeTo(null);  
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        frame.setVisible(true);  
    }  
}  
