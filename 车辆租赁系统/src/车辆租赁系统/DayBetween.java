package ��������ϵͳ;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import javax.swing.JOptionPane;

public class DayBetween {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
	}

}
class Between{
	Between(String data1,String date2,String M){
		
	SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
	Calendar cal = Calendar.getInstance();  //�������ʱ��
    Date dt = null,dt2=null; 
    try { 
      dt = sdf.parse(data1);    //��һ��ʱ���ʽ���ַ���ת��Ϊ���벻ͬ��gettimee�����ǰ�date����ת��Ϊ����
      cal.setTime(dt);    //����ʱ��
    } catch (ParseException e) { 
      // TODO Auto-generated catch block 
      e.printStackTrace(); 
    } 
    int y1 = cal.get(Calendar.YEAR); 
    int m1 = cal.get(Calendar.MONTH) + 1; 
    int d1 = cal.get(Calendar.DAY_OF_MONTH);
    
    try { 
        dt2 = sdf.parse(date2); 
        cal.setTime(dt2); 
      } catch (ParseException e) { 
        // TODO Auto-generated catch block 
        e.printStackTrace(); 
      } 
      int y2 = cal.get(Calendar.YEAR); 
      int m2 = cal.get(Calendar.MONTH) + 1; 
      int d2 = cal.get(Calendar.DAY_OF_MONTH);
    

    
    
    
    
    cal.set(y1, m1, d1);
    long time_1 = cal.getTimeInMillis();

    cal.set(y2, m2, d2);
    long time_2 = cal.getTimeInMillis();

    long space = (time_2 - time_1) / (1000 * 60 * 60 * 24);
    double m=Double.parseDouble(M);
    //Double.parseDouble(s)
    JOptionPane.showMessageDialog(null,"������"+space*m+"Ԫ",
			 "����",JOptionPane.INFORMATION_MESSAGE);
    
    
	}
}
