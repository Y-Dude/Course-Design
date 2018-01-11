package 车辆租赁系统;

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
		// TODO 自动生成的方法存根
	}

}
class Between{
	Between(String data1,String date2,String M){
		
	SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
	Calendar cal = Calendar.getInstance();  //获得现在时间
    Date dt = null,dt2=null; 
    try { 
      dt = sdf.parse(data1);    //把一个时间格式的字符串转换为毫秒不同于gettimee（）是吧date对象转换为毫秒
      cal.setTime(dt);    //设置时间
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
    JOptionPane.showMessageDialog(null,"结算金额"+space*m+"元",
			 "结算",JOptionPane.INFORMATION_MESSAGE);
    
    
	}
}
