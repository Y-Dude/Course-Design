package 显示表情;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

public class Face
{
   public static void main(String[] args)
   {
	   ButtonFrame frame = new ButtonFrame();
       frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       frame.setLocation(480,100);         //框架位置
       frame.setVisible(true);
   }
}


class ButtonFrame extends JFrame
{
   /**
	 * 
	 */
	private static final long serialVersionUID = -751762414259943794L;
DrawButton myPanel=new DrawButton();
   String choice=null;                  //首先显示笑脸
   public ButtonFrame()
   {
      setTitle("Face");
      setSize(400,400);

      JPanel button = new JPanel();

      // create buttons
      JButton cryButton = new JButton("流泪ing");
      JButton smileButton = new JButton("微笑ing");
      JButton angryButton = new JButton("生气ing");
      JButton exitButton = new JButton("退出");

      // add buttons to panel
      button.add(cryButton);
      button.add(smileButton);
      button.add(angryButton);
      button.add(exitButton);

      //图像
      add(button,BorderLayout.SOUTH);              //按钮置于下面
      add(myPanel,BorderLayout.CENTER);            //表情面板居中

      // 4个按钮设置
      cryButton.addActionListener(new ButtonAction("流泪ing"));
      smileButton.addActionListener(new ButtonAction("微笑ing"));
	  angryButton.addActionListener(new ButtonAction("生气ing"));
	  exitButton.addActionListener(new ButtonAction("退出"));
   }
   
   class ButtonAction implements ActionListener
   {
       private String str;
   	   public ButtonAction(String str){this.str=str;}
   	   public void actionPerformed(ActionEvent e)
   	   {
		   choice=str;
   		   repaint();         //重绘
   		}
    }
   
    class DrawButton extends JPanel
	{
		/**
		 * 
		 */
		private static final long serialVersionUID = -9080672025615352645L;

		public void paintComponent(Graphics g)
		{
		    super.paintComponent(g);
			Graphics2D g2=(Graphics2D) g;

            if(choice.equals("微笑ing"))                    //画微笑的脸
			{
				Ellipse2D ellipse=new Ellipse2D.Double(90,90,220,180);         //脸型利用画椭圆类
				g2.draw(ellipse);

				Arc2D arc1=new Arc2D.Double(90,150,130,150,70,40,Arc2D.OPEN);     //眉毛利用画圆弧类
				g2.draw(arc1);
				Arc2D arc2=new Arc2D.Double(180,150,130,150,70,40,Arc2D.OPEN);
				g2.draw(arc2);

				Ellipse2D ellipse1=new Ellipse2D.Double(135,160,40,12);           //眼眶
				g2.draw(ellipse1);
				Ellipse2D ellipse2=new Ellipse2D.Double(225,160,40,12);
				g2.draw(ellipse2);

				Ellipse2D circle1 = new Ellipse2D.Double();                   //眼珠
			    circle1.setFrameFromCenter(154,166,160,172);
			    g2.setPaint(Color.BLACK);
				g2.fill(circle1);
				Ellipse2D circle2 = new Ellipse2D.Double();
			    circle2.setFrameFromCenter(244,166,250,172);
				g2.fill(circle2);

				Arc2D arc3=new Arc2D.Double(130,70,140,160,238,64,Arc2D.OPEN);       //嘴
				g2.draw(arc3);
				Arc2D arc4=new Arc2D.Double(150,100,100,140,223,94,Arc2D.OPEN);
      			g2.draw(arc4);
			}
			if(choice.equals("流泪ing"))                               //画流泪的脸
			{
                Ellipse2D ellipse=new Ellipse2D.Double(90,90,220,180);
		        g2.draw(ellipse);

		        Arc2D arc1=new Arc2D.Double(90,150,130,150,70,40,Arc2D.OPEN);   //眉毛
		        g2.draw(arc1);
		        Arc2D arc2=new Arc2D.Double(180,150,130,150,70,40,Arc2D.OPEN);
		        g2.draw(arc2);

		        Ellipse2D ellipse1=new Ellipse2D.Double(135,160,40,12);     //眼睛
		        g2.draw(ellipse1);
		        Ellipse2D ellipse2=new Ellipse2D.Double(225,160,40,12);
		        g2.draw(ellipse2);

		        Ellipse2D circle1 = new Ellipse2D.Double();                 
		  	    circle1.setFrameFromCenter(154,166,160,172);
		  	    g2.setPaint(Color.BLACK);
		        g2.fill(circle1);
		        Ellipse2D circle2 = new Ellipse2D.Double();
		  	    circle2.setFrameFromCenter(244,166,250,172);
		        g2.fill(circle2);

		       Ellipse2D circle3 = new Ellipse2D.Double();                //眼泪
		  	    circle3.setFrameFromCenter(154,185,156,187);
		        g2.draw(circle3);
		        Ellipse2D circle4 = new Ellipse2D.Double();
		  	    circle4.setFrameFromCenter(154,200,157,203);
		        g2.draw(circle4);
		        Ellipse2D circle5 = new Ellipse2D.Double();
		  	    circle5.setFrameFromCenter(244,185,246,187);
		        g2.draw(circle5);
		        Ellipse2D circle6 = new Ellipse2D.Double();
		  	    circle6.setFrameFromCenter(244,200,247,203);
		        g2.draw(circle6);

		        Arc2D arc3=new Arc2D.Double(130,210,140,160,60,60,Arc2D.OPEN);
		        g2.draw(arc3);
		        Arc2D arc4=new Arc2D.Double(150,200,100,140,42,94,Arc2D.OPEN);
                g2.draw(arc4);
			}
			if(choice.equals("生气ing"))                             //画生气的脸
			{
                Ellipse2D ellipse=new Ellipse2D.Double(90,90,220,180);
		        g2.setPaint(Color.BLACK);
		        g2.draw(ellipse);

		        Line2D line1=new Line2D.Double(130,130,188,164);            //眉毛
		        g2.setPaint(Color.BLACK);
		        g2.draw(line1);
		        Line2D line2=new Line2D.Double(210,164,268,130);
		        g2.draw(line2);

		        Ellipse2D ellipse1=new Ellipse2D.Double(135,160,40,12);
		        g2.setPaint(Color.BLACK);
		        g2.draw(ellipse1);
		        Ellipse2D ellipse2=new Ellipse2D.Double(225,160,40,12);
		        g2.draw(ellipse2);

		        Ellipse2D circle1 = new Ellipse2D.Double();
		  	    circle1.setFrameFromCenter(154,166,160,172);
		  	    g2.setPaint(Color.BLACK);
		        g2.fill(circle1);
		        Ellipse2D circle2 = new Ellipse2D.Double();
		  	    circle2.setFrameFromCenter(244,166,250,172);
		        g2.fill(circle2);

		        Rectangle2D rect=new Rectangle2D.Double(155,210,100,20);
		        g2.setPaint(Color.BLACK);
		        g2.draw(rect);

			}
			if(choice.equals("退出"))                        //退出
			{
				System.exit(0);
			}
	    }
	}
}

