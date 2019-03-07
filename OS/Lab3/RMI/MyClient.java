    import java.rmi.*;
	import java.util.*;  
    public class MyClient{  
    public static void main(String args[]){  
    try{  
    Adder stub=(Adder)Naming.lookup("rmi://localhost:5000/sonoo");
Scanner s= new Scanner(System.in);
System.out.println("Enter two numbers");  
    System.out.println(stub.add(s.nextInt(),s.nextInt()));  
    }catch(Exception e){}  
    }  
    }  
