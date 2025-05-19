class Swap
{
public static void main(String args[])
{
int a=10;
int b=20;
System.out.println("unswapped numbers");
System.out.println(a);
System.out.println(b);
a=a*b;
b=a/b;
a=a/b;
System.out.println("swapped numbers");
System.out.println(a);
System.out.println(b);
}
}
