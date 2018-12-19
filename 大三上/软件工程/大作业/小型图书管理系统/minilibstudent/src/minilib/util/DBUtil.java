package minilib.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBUtil {
   
	private static String rootname="root";
	private static String rootpass="root";
	
	private static String driver = "com.mysql.jdbc.Driver";
	
	private static String url="jdbc:mysql://localhost:3306/book";
	
	public static Connection getConnection()throws InstantiationException,IllegalAccessException,ClassNotFoundException,SQLException{
		Class.forName(driver).newInstance();
		return DriverManager.getConnection(url,rootname,rootpass);
	}
}
