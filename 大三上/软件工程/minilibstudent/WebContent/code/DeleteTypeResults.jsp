<%@ page language="java" contentType="text/html; charset=UTF-8"
    import = "java.util.*"
	import = "minilib.vo.*"
	import = "minilib.dao.*" 
	import = "minilib.util.*" 
	import = "minilib.action.*"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>删除图书分类结果</title>
</head>
 <body background="../img/top.jpg">
<%
  out.println(request.getAttribute("deleteType"));
%>

</body>
</html>