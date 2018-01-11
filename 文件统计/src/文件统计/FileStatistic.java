package 文件统计;
import java.util.*;  
import java.io.File;  
import java.io.FileReader;  
import javax.swing.JOptionPane;  
  
public class FileStatistic{
   public static void main( String[ ] args ) throws Exception {  
       String str = JOptionPane.showInputDialog("请输入文件名(注意请输入文件所在具体路径)：");  
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
           JOptionPane.showMessageDialog(null, "字符数:"+String.valueOf(count) +"\n"+"单词数:"+String.valueOf(words.length));  
       }   
       else   
           JOptionPane.showMessageDialog(null, "字符数:0"+"\n"+"单词数:0");  
   }   
}