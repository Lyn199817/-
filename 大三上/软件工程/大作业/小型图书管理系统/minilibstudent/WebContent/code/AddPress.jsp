<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core_rt" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>增加出版社</title>
</head>
 <body background="../img/top.jpg">
${message}

<form method="post" action="addCodePressManageCodeAction.action">
<h1 align="center"><font face="华文楷体" color="#8B2323">
增加出版社</font><br/><br/></h1>
<p align="center"><font face="宋体">
现存出版社
<select name="">
	<c:forEach items="${requestScope.bookCodePressList}" var="booktype" varStatus="status">
	<option value="${booktype.codeId}">${booktype.codeName}
	</c:forEach>
</select><br><br>


  出版社编号<input type="text" name="code.codeId" value=""><br><br>
  出版社名称<input type="text" name="code.codeName" value=""><br><br>
 <input type="submit" name = "sumbit" value = "增加出版社">

</font>
</p>
</body>
</html>