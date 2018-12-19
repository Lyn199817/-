<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>登录界面</title>
</head>
<body>
<form name="form1"  action="LoginServelet" method="post">
<h2> 用户登录</h2>
用户名<input name="username" type="text"><br>
密码<input name="userpass" type="password"><br>
<br> <input type="reset" value="重置"> <input type="submit" value="提交">
</form>
</body>
</html>
