package minilib.action;
import java.sql.Connection;
import java.util.List;
import javax.servlet.http.HttpServletRequest;
import minilib.dao.ManageTitlesDao;
import minilib.vo.Title;
import org.apache.struts2.ServletActionContext;
import com.opensymphony.xwork2.ActionSupport;
public class ManageTitlesAction extends ActionSupport{
	private Title  book;
public Title getBook() {
		return book;
	}
	public void setBook(Title book) {
		this.book = book;
	}
public String addTitle() throws Exception{
	String restadd = INPUT;
	ManageTitlesDao mtadd = new ManageTitlesDao();
	System.out.print("----book.Title-----"+book.getTitle());
	mtadd.savaTitle(book);
	restadd = "addbook";
	HttpServletRequest req = ServletActionContext.getRequest();
	req.setAttribute("message", "添加成功继续添加！");
	System.out.println("----add-----"+book.getTypeid()+book.getTitle());
	return restadd;
}
public String findTitle() throws Exception{
	
	String rest=INPUT;
	ManageTitlesDao mt=new ManageTitlesDao();
	List allTitlesList=mt.findAll(book.getTitle());
	HttpServletRequest request=ServletActionContext.getRequest();
	request.setAttribute("alltitleslist", allTitlesList);
	rest= "querybook";
	System.out.println("----find-----");
	return rest;
}
public String findBookType() throws Exception{
	String  restType=INPUT;
	ManageTitlesDao mttype=new ManageTitlesDao();
	List allTypeList=mttype.findBookType();
	HttpServletRequest request=ServletActionContext.getRequest();
	request.setAttribute("alltypelist", allTypeList);
	restType="booktype";
	System.out.println("----findBookType-----");
	return restType;
	
}
public String deleteTitle() throws Exception{
	String restdelete = INPUT;
	ManageTitlesDao mttype = new ManageTitlesDao();
	mttype.deleteTitle(book);
	HttpServletRequest request = ServletActionContext.getRequest();
	restdelete = "deletebook";
	System.out.println("====deletebook====");
	return restdelete;
}
}
