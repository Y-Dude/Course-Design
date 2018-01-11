package 简单文本编辑器;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.io.*;

public class TextEditor
{
	public static void main(String[] args)
	{
		TextEditorFrame  frame = new TextEditorFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		frame.pack();
	}
}

class TextEditorFrame extends JFrame implements ActionListener
{
	JTextArea text;  //文本编辑区域
	JScrollPane sp;		//JScrolPane当组件内容大于显示区域时自动产生滚动
	Container c=getContentPane();
	public TextEditorFrame()
	{
		c.setLayout(new BorderLayout());
        setSize(400,300);
        setTitle("文本编译器");
        setLocationRelativeTo(null);

        JMenuBar menuBar = new JMenuBar();  //新建菜单栏
        setJMenuBar(menuBar);//设定窗口的菜单栏
        JMenu fileMenu = new JMenu("File");//新建一个菜单
        menuBar.add(fileMenu); //将菜单加入菜单栏中
        
  		JMenuItem new1 = new JMenuItem("New"); //将项目新建并加入菜单中
        fileMenu.add(new1);
  		JMenuItem open = new JMenuItem("Open");
  		fileMenu.add(open);
        JMenuItem save = new JMenuItem("Save");
        fileMenu.add(save);
        JMenuItem exit = new JMenuItem("Exit");
        fileMenu.add(exit);
        text=new JTextArea("welcome to ykp's TEXT Editor",20,50); //新建文本域,长宽为20 50
        sp = new JScrollPane(text);//新建创建一个显示指定组件内容的JScrolPane
        add(sp,BorderLayout.CENTER);//将JScrollPane放入内容窗格
       //菜单项的监听器
        new1.addActionListener(this);
        open.addActionListener(this);
        save.addActionListener(this);
        exit.addActionListener(this);
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getActionCommand()=="New")
		{
			text.setText(""); //文本域设置为空
		}
		if(e.getActionCommand()=="Open")
		{
			text.setText(""); //清除文本中原有内容如果不加这句，文件内容将在先前内容之后显示
			try {openfile();}
			catch(IOException ex){ex.printStackTrace();}
		}
		if(e.getActionCommand()=="Save")
		{
			try{savefile();}//保存
			catch(IOException ex){ex.printStackTrace(); }
		}
		if(e.getActionCommand()=="Exit")
		{
			System.exit(0);
		}
	}
	
	public void openfile() throws IOException
	{
		FileDialog fd=new FileDialog(this,"Open",FileDialog.LOAD);
		//java.awt.FileDialog ,public static final int LOAD 和Save
		fd.setVisible(true);
		FileReader fr=new FileReader( fd.getDirectory()+fd.getFile());
		int n=0;
		int num=100; //设定每行的字符数
		while((n=fr.read())!=-1)
		{
			text.append(""+(char)n);
			num--;
			if(num==0)
			{
				text.append("\n");
				num=100;
			}
		}
		fr.close();
	}
	
	public void savefile() throws IOException
	{
		FileDialog fd=new FileDialog(this,"Save",FileDialog.SAVE);  
		fd.setVisible(true); //必须设为可见
		FileWriter fw=new FileWriter( fd.getDirectory()+fd.getFile());//用于写入字符流,要写入原始字节流,使用 FileOutputStream
		for(int i=0;i<text.getText().length();i++)                       //用于构造与fd 保存的文件相关联的对象
		{
			fw.write(text.getText().charAt(i)); //写入文件
		}
		fw.close();
	}
}
