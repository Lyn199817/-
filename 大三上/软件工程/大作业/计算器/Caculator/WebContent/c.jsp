<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Control-Type" content ="text/html; charset="UTF-8">
<title>简单计算器</title>
</head>
<body>
简单计算器<br>
<form action="Control" method="post">
   <input type="text" name="num1" value="">
   <select name="oper">
      <option value="+" select> + </option>
      <option value="-"> - </option>
      <option value="*"> * </option>
      <option value="/"> / </option>
    </select>
    <input type="text" name="num2" value="">
    <input type="submit" value="=">${result}
</form>
</body>
</html>