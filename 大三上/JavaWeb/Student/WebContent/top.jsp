<%@ page language="java" contentType="text/html; charset=utf-8"
	    pageEncoding="utf-8"%>
	    <%@ page import="vo.*"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Insert title here</title>
</head>
<body bgcolor="#eeeeee" >
  <p class="title" align="center"><font face="华文楷体" color="#8B2323">
<%
	User u=(User) session.getAttribute("user");
	out.print("考号："+u.getStudno());
	out.print("姓名："+u.getRealName());
%>
学院：计信学院
</p></font>
	</body>
	</html>
