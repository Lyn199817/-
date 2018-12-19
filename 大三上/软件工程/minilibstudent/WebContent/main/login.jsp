<!-- 
/***********************************************************
*													
*														
*	项目名称：				
*	子系统名：			
*	功能名称：	
*	完成人员：					
*	完成时间：					
*								
*									
************************************************************/
-->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
  <head>
    <title>小型图书资料管理系统登录页面</title>
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
  </head>
  <body background="../img/login.jpg">
	<form method="post" action="LoginAction.action" name="frm">
	<h1 align="center"><font face="华文楷体" color="#8B2323">
	  小型图书资料管理系统</font><br/><br/></h1>
	  <p align="center"><font face="宋体">
	    用户账户： <input type="text" size="30" name="user.username" value="admin"><br/><br/>
	    登录密码： <input type="password" size="31" name="user.userpass" value="123456"><br/><br/>
	  <input type="submit" value="登录系统" >
	  <input type="reset" value="重新填写" ><br/><br/>
      <p align="center"><font>Copyright@ 2009-2018 版权所有 辽宁师范大学</font></p>
	</form>
  </body>
</html>
