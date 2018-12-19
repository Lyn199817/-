package servelets;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import bean.UserBean;

public class LoginServelet extends HttpServlet {
	private String name;
	private String pass;
	public void doGet(HttpServletRequest request,HttpServletResponse response)
	throws IOException,ServletException{
		name=(String)request.getParameter("username");
		pass=(String)request.getParameter("userpass");
		UserBean u=new UserBean();
		boolean b=u.validate(name, pass);
		String forward = null;
		if(b){
			HttpSession session=request.getSession(true);
			session.setAttribute("username",name);
			forward = "success.jsp";
		}else{
			forward="failure.jsp";
		}
		RequestDispatcher dispatcher=request.getRequestDispatcher(forward);
		dispatcher.forward(request,response);
	}
	public void doPost(HttpServletRequest request,HttpServletResponse response)
	throws IOException,ServletException{
		doGet(request,response);
	}


}
