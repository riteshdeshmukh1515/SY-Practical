
class TestOverloading
{
public static void main(String[] arg)
 {
 Adder d = new Adder();
d.Add(10,20);
System.out.println("Sum of two numbers : "+d.Add(10,20));
d.Add(10,20,30);
System.out.println("Sum of three numbers : "+d.Add(10,20,30));
 }
 }
