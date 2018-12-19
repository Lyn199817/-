package minilib.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import minilib.util.DBUtil;
import minilib.vo.CodeBookType;
import minilib.vo.Title;
import com.mysql.jdbc.Statement;
public class ManageTitlesDao {
public List findAll(String name) {
List list=new ArrayList();
try{
	Connection conn=DBUtil.getConnection();
	String sql="select * from t_book where title like '%"+name+"%'";

	System.out.print("sql="+sql);
	PreparedStatement pstmt=conn.prepareStatement(sql);
	ResultSet rs=pstmt.executeQuery();
	while(rs.next()){
		Title title=new Title();
		title.setIsbn(rs.getString(3));
		title.setTitle(rs.getString(5));
		title.setAuthors(rs.getString(6));
		title.setPressid(rs.getString(8));
		list.add(title);
	}
	rs.close();
	pstmt.close();
	conn.close();
}catch(InstantiationException e){
	e.printStackTrace();
}catch(IllegalAccessException e){
	e.printStackTrace();
}catch(ClassNotFoundException e){
	e.printStackTrace();
}catch(SQLException e){
	e.printStackTrace();
}
return list;
}
public void savaTitle(Title book) 
throws InstantiationException,IllegalAccessException,ClassNotFoundException,SQLException{
	Connection conn=DBUtil.getConnection();	
	String sql="insert into t_book(isbn,title,authors) values('"
	+book.getIsbn()+"','"+book.getTitle()+"','"+book.getAuthors()+"')";
	
	Statement stmt=(Statement) conn.createStatement();
	stmt.execute(sql);
	stmt.close();
	
}
public List findBookType()
throws InstantiationException,IllegalAccessException,ClassNotFoundException,SQLException{
	List list =new ArrayList();
	Connection conn=DBUtil.getConnection();	
	Statement stmt=(Statement) conn.createStatement();
	String strsql="select ";
	strsql=strsql+"codeid,codename";
	strsql=strsql+" from code_booktype order by codeid";
	System.out.print("****strsql="+strsql+"******");
	ResultSet rs=stmt.executeQuery(strsql);
	while(rs.next()){
		CodeBookType booktype=new CodeBookType();
		booktype.setCodeId(rs.getString(1));
		booktype.setCodeName(rs.getString(2));
		list.add(booktype);
		
	}
	rs.close();
	stmt.close();
	conn.close();
	return list;
}

public void deleteTitle(Title book)
throws InstantiationException,IllegalAccessException,ClassNotFoundException, SQLException{
	Connection conn = DBUtil.getConnection();
	String sql ="delete from t_book where title='"+book.getTitle()+"'";
	Statement stmt=(Statement) conn.createStatement();
	stmt.executeUpdate(sql);
	stmt.close();
	conn.close();
}
}
