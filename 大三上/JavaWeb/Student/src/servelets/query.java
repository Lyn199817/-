package servelets;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import util.DBUtil;
/**
 * Servlet implementation class query
 */
@WebServlet("/query")
public class query extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public query() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String studno=request.getParameter("studno");
		boolean mark = true;
		String query=request.getParameter("query");
		response.setContentType("text/html");
		response.setCharacterEncoding("UTF-8");
		String query1=new String(query.getBytes("ISO-8859-1"),"utf-8");
		try{
			if(query1.equals("查询")){
			String strSQL = "select * from answer where studno=?";
			Connection con =DBUtil.getConnection();
			PreparedStatement pstm = con.prepareStatement(strSQL);
			pstm.setString(1, studno);
			
			
			ResultSet rst = pstm.executeQuery();
			if(rst.next()){
				String stud=rst.getString("studno");
				String realname=rst.getString("realname");
				int grade1=rst.getInt("grade1");
				int grade2=rst.getInt("grade2");
				HttpSession session=request.getSession();
				session.setAttribute("studno", stud);
				session.setAttribute("realname",realname);
				session.setAttribute("grade1", grade1);
				session.setAttribute("grade2", grade2);
				
			}
			else{
				mark = false;
			}
						
			pstm.close();
			con.close();
			
			if(mark==true)
				response.sendRedirect("grade.jsp");
			else
				response.sendRedirect("topic.jsp");
			}
			else{
				String strSQL = "select * from answer where studno=?";
				Connection con = DBUtil.getConnection();
				PreparedStatement pstm = con.prepareStatement(strSQL);
				pstm.setString(1, studno);
				
				
				ResultSet rst = pstm.executeQuery();
				if(rst.next()){
					String number=rst.getString("studno");
					String realname=rst.getString("realname");
					int grade1=rst.getInt("grade1");
					int grade2=rst.getInt("grade2");
					
					HttpSession session=request.getSession();
					session.setAttribute("number", number);
					session.setAttribute("realname", realname);
					session.setAttribute("grade1", grade1);
					session.setAttribute("grade2", grade2);
				}else{
					mark=false;
				}
				pstm.close();
				con.close();
				if(mark==true)
					response.sendRedirect("grade2.jsp");
			}
		}
		
catch(Exception e){
			e.printStackTrace();
		}
	}

}


