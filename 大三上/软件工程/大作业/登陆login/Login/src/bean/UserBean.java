package bean;

public class UserBean {
	private String username;
	private String userpass;
	public String getUsername(){
		return username;
	}
	public void setUsername(String username){
		this.username=username;
	}
    public String getUserpass(){
    	return userpass;
    }
    public void setUserpass(String userpass){
    	this.userpass=userpass;
    }
    public boolean validate(String username,String userpass){
    	if(username.equals("zhangsan")&&userpass.equals("123456"))
    		return true;
    	else
    		return false;
    }
}

