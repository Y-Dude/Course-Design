package ���ı��༭��;
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
	JTextArea text;  //�ı��༭����
	JScrollPane sp;		//JScrolPane��������ݴ�����ʾ����ʱ�Զ���������
	Container c=getContentPane();
	public TextEditorFrame()
	{
		c.setLayout(new BorderLayout());
        setSize(400,300);
        setTitle("�ı�������");
        setLocationRelativeTo(null);

        JMenuBar menuBar = new JMenuBar();  //�½��˵���
        setJMenuBar(menuBar);//�趨���ڵĲ˵���
        JMenu fileMenu = new JMenu("File");//�½�һ���˵�
        menuBar.add(fileMenu); //���˵�����˵�����
        
  		JMenuItem new1 = new JMenuItem("New"); //����Ŀ�½�������˵���
        fileMenu.add(new1);
  		JMenuItem open = new JMenuItem("Open");
  		fileMenu.add(open);
        JMenuItem save = new JMenuItem("Save");
        fileMenu.add(save);
        JMenuItem exit = new JMenuItem("Exit");
        fileMenu.add(exit);
        text=new JTextArea("welcome to ykp's TEXT Editor",20,50); //�½��ı���,����Ϊ20 50
        sp = new JScrollPane(text);//�½�����һ����ʾָ��������ݵ�JScrolPane
        add(sp,BorderLayout.CENTER);//��JScrollPane�������ݴ���
       //�˵���ļ�����
        new1.addActionListener(this);
        open.addActionListener(this);
        save.addActionListener(this);
        exit.addActionListener(this);
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getActionCommand()=="New")
		{
			text.setText(""); //�ı�������Ϊ��
		}
		if(e.getActionCommand()=="Open")
		{
			text.setText(""); //����ı���ԭ���������������䣬�ļ����ݽ�����ǰ����֮����ʾ
			try {openfile();}
			catch(IOException ex){ex.printStackTrace();}
		}
		if(e.getActionCommand()=="Save")
		{
			try{savefile();}//����
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
		//java.awt.FileDialog ,public static final int LOAD ��Save
		fd.setVisible(true);
		FileReader fr=new FileReader( fd.getDirectory()+fd.getFile());
		int n=0;
		int num=100; //�趨ÿ�е��ַ���
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
		fd.setVisible(true); //������Ϊ�ɼ�
		FileWriter fw=new FileWriter( fd.getDirectory()+fd.getFile());//����д���ַ���,Ҫд��ԭʼ�ֽ���,ʹ�� FileOutputStream
		for(int i=0;i<text.getText().length();i++)                       //���ڹ�����fd ������ļ�������Ķ���
		{
			fw.write(text.getText().charAt(i)); //д���ļ�
		}
		fw.close();
	}
}
