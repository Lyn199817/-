package action;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

import org.apache.struts2.ServletActionContext;

import com.opensymphony.xwork2.ActionSupport;

import vo.User;

public class LoginAction extends ActionSupport {
     private User user;
     public User getUser() {
		return user;
	}
	public void setUser(User user) {
		this.user = user;
	}
	public String execute() throws Exception{
    	if(user.getUsername().equals("zhangsan")&&(user.getUserpass().equals("123456")))
 		{
 			HttpServletRequest request = ServletActionContext.getRequest();
 			HttpSession session = request.getSession();
 			session.setAttribute("username", user.getUsername());
 			return "success";
 		}
 		else {
 			return "error";
 		}
     }
}
