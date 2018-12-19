package servelets;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import vo.User;
import util.DBUtil;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class answer1
 */
@WebServlet("/answer1")
public class answer1 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public answer1() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse response)
	 */
    
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String s[]={"a","b"};
		String result1="";
		String result2="";
		int n=0;
		for(int i=0;i<s.length;i++){
			String answer1=request.getParameter("r"+i);
			result1+=answer1;
			System.out.println(answer1);
			if(answer1.equals(s[i])){
				n++;
			}
		}
		System.out.print("answer："+result1);
		String strSQL = "insert into answer values(?,?,?,?,?,?,?)";
		HttpSession session = request.getSession();
		User u = (User)session.getAttribute("user");
		response.setContentType("text/html");
		response.setCharacterEncoding("UTF-8");
		try{
			Connection con = DBUtil.getConnection();
			PreparedStatement pstm = con.prepareStatement(strSQL);
			pstm.setString(1, u.getUser());
			pstm.setString(2, u.getStudno());
			pstm.setString(3, u.getRealName());
			pstm.setString(4, result1);
			pstm.setString(5, result2);
			pstm.setInt(6, n);
			pstm.setInt(7, 0);
			pstm.executeUpdate();
			pstm.close();			
			con.close();
			response.sendRedirect("topic2.jsp");
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}

}
