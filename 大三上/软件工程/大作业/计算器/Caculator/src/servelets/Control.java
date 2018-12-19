package servelets;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import service.Computer;

public class Control extends HttpServlet {
     private static final long serialVersionUID =1L;
     protected void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException{
    	 String num1 = request.getParameter("num1");
    	 String num2 = request.getParameter("num2");
    	 String oper = request.getParameter("oper");
    	 
    	 Computer c = new Computer();
    	 String result = c.computer(num1, num2, oper);
    	 request.setAttribute("result", result);
    	 String forward = "/c.jsp";
    	 RequestDispatcher rd = request.getRequestDispatcher(forward);
    	 rd.forward(request, response);
     }
     protected void doPost(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException{
    	 doGet(request,response);
     }
}
