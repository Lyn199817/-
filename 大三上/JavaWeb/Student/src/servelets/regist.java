package servelets;
import java.io.IOException;
import java.io.PrintWriter;
import util.DBUtil;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.sql.*;
/**
 * Servlet implementation class regist
 */
@WebServlet("/regist")
public class regist extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public regist() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String user=request.getParameter("user");
		String pwd=request.getParameter("pwd");
		String realname=request.getParameter("realname");
		String age=request.getParameter("age");
		String studno=request.getParameter("studno");
		String sql="insert into user values("+"'"+user+"',"+"'"+pwd+"',"  +"'"+realname+"',"+"'"+age+"',"+"'"+studno+"')" ;
		System.out.print("-----regist-----");
		PrintWriter out=response.getWriter();
		try{
			   
			   Connection con=DBUtil.getConnection();;
			   Statement stm=con.createStatement();
			   stm.executeUpdate(sql);
			   out.print("success!+<br>");
			   out.print("<a href='login.jsp'>login</a>");
			  
			   stm.close();
			   con.close();
			
			
		}catch(Exception e){
			e.printStackTrace();
		}
	}

}
