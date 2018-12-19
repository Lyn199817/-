package servelets;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import vo.User;
import util.DBUtil;
/**
 * Servlet implementation class login
 */
@WebServlet("/login")
public class login extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public login() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String login=request.getParameter("login");
		response.setContentType("text/html");
		response.setCharacterEncoding("UTF-8");
		String login1=new String(login.getBytes("ISO-8859-1"),"utf-8");
		if(login1.equals("登录系统")){
		
		String user=request.getParameter("user");
		String pwd=request.getParameter("pwd");
		String sql = "select * from user where user=? and pwd=?";
		PrintWriter out=response.getWriter();
		boolean mark = true;
		try{
			
			Connection con = DBUtil.getConnection();
			PreparedStatement pstm = con.prepareStatement(sql);
			pstm.setString(1, user);
			pstm.setString(2, pwd);
			
			ResultSet rst = pstm.executeQuery();
			if(rst.next()){
				String name = rst.getString("realname");
				String age = rst.getString("age");
				String studno = rst.getString("studno");

				
				User u = new User();
				u.setUser(user); u.setPwd(pwd); u.setAge(age);
				u.setRealName(name); u.setStudno(studno);
				
				HttpSession session = request.getSession();
				
				session.setAttribute("user",u);
				
			}
			else{
				mark = false;
			}
						
			pstm.close();
			con.close();
			
			if(mark==true)
				response.sendRedirect("main.jsp");
			else
				out.print("not regist");
				out.print("<a href='login.jsp'>return</a>");
			
		}
	
catch(Exception e){
			e.printStackTrace();
		}
		
	}else{
		response.sendRedirect("regist.jsp");
	}
	
	}

}
