<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>总成绩查询页面</title>
</head>
<body>
<%
	String number=(String)session.getAttribute("studno");
	String realname=(String)session.getAttribute("realname");
	int grade1=(Integer)session.getAttribute("grade1");
	int grade2=(Integer)session.getAttribute("grade2");
	int sum=grade1+grade2;
	out.print("考号："+number+"<br>"+"<br>");
	out.print("姓名："+realname+"<br>"+"<br>");
	out.print("总成绩："+sum);
%>
</body>
</html>
