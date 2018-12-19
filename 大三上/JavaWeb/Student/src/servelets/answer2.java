package servelets;

import java.sql.*;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import vo.User;
import util.DBUtil;
/**
 * Servlet implementation class Answer2
 */
@WebServlet("/answer2")
public class answer2 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public answer2() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String s[]={"ab","cd"};
		String result2="";
		int n=0;
		for(int i=0;i<s.length;i++){
			String answer2[]=request.getParameterValues("r"+i);
			String str="";
			for(int j=0;j<answer2.length;j++){
				str+=answer2[j];
			}
			result2+=str;
			if(str.equals(s[i])){
				n++;
			}
		}
		System.out.print("answer2:"+result2);
		HttpSession session = request.getSession();
		User u = (User)session.getAttribute("user");
		String strSQL = "update answer set grade2='" +n+"' where user='"+u.getUser()+"'"; 
		
		try{
			Connection con = DBUtil.getConnection();
			Statement stm = con.createStatement();	
			stm.executeUpdate(strSQL);
			stm.close();
			con.close();
			response.sendRedirect("query.jsp");
			
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}

}
