<%@ page language="java" contentType="text/html; charset=UTF-8"
	import="java.util.*" import="minilib.vo.CodeBookType" import="minilib.vo.Title"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>增加图书</title>
</head>
 <body background="../img/top.jpg">
<%request.setCharacterEncoding("UTF-8"); %>
${message}
<form method="post" action="addTitleManageTitlesAction.action">
<%List listtype=(List)request.getAttribute("alltypelist"); %>
<h1 align="center"><font face="华文楷体" color="#8B2323">
增加图书</font><br/><br/></h1>
<p align="center"><font face="宋体">
图书类别：
<select name="book.typeid">
	<%
	for(int i=0;i<listtype.size();i++){
		CodeBookType booktype=(CodeBookType)listtype.get(i);
	out.print("<option value'");
	out.print(booktype.getCodeId());
	out.print("'>");
	out.print(booktype.getCodeName());
	out.print("</option>");
	out.print("<br>");
	}
	%>
</select><br/><br/>
ISBN：
<input type="text" name="book.isbn" >
<br/><br/>
书名：
<input type="text" name="book.title" >
<br/><br/>
作者：
<input type="text" name="book.authors" ><br><br>
<input type="submit" name = "sumbit" value = "增加图书">
</font>


</form>
</body>
</html>