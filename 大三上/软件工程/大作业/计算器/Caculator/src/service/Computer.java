package service;

public class Computer {
      public String computer(String num1,String num2,String oper){
    	  String result = null;
    	  double dnum1 = 0.0;
    	  double dnum2 = 0.0;
      try {
    	  dnum1 = Double.parseDouble(num1);
    	  dnum2 = Double.parseDouble(num2);
    	  if(oper.equals("+")) {
    		  result = dnum1+dnum2+" ";//将double型转为字符型
    	  }else if(oper.equals("-")) {
    		  result = dnum1-dnum2+" ";
    	  }else if(oper.equals("*")) {
    		  result = dnum1*dnum2+" ";
    	  }else if(oper.equals("/")) {
    		  result = dnum1/dnum2+" ";
    	  }
      }catch(Exception e) {}
      return result;
      }
}
