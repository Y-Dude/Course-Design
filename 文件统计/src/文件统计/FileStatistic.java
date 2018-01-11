package �ļ�ͳ��;
import java.util.*;  
import java.io.File;  
import java.io.FileReader;  
import javax.swing.JOptionPane;  
  
public class FileStatistic{
   public static void main( String[ ] args ) throws Exception {  
       String str = JOptionPane.showInputDialog("�������ļ���(ע���������ļ����ھ���·��)��");  
       File file = new File(str);  
       FileReader reader = new FileReader(file);  
       int length = (int)file.length();  
       char[] chars = new char[length];  
       reader.read(chars);  
       reader.close();  
       String s = String.valueOf(chars);  
         
       int count = 0;  
       int n = chars.length;  
       for(int i = 0; i < n ; i++)  
       {  
           if(chars[i] >= 'a' && chars[i] <= 'z')  
           {  
               count ++;  
           }  
       }  
         
       String[ ] words = s.replaceAll( "[^a-zA-Z]+", " " ).trim( ).split( " " );  
  
       if ( words.length > 0 ) {  
           TreeSet<Integer> lengths = new TreeSet<Integer>( );   
           for ( String word: words )  
               lengths.add( word.length( ) );  
           JOptionPane.showMessageDialog(null, "�ַ���:"+String.valueOf(count) +"\n"+"������:"+String.valueOf(words.length));  
       }   
       else   
           JOptionPane.showMessageDialog(null, "�ַ���:0"+"\n"+"������:0");  
   }   
}