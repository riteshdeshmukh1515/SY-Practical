//program for handling exception using throw

class EXThrow
{
static void checkAge(int age) 
{
if(age<18)
{
 throw new ArithmeticException("Access denied.you must be at least 18 yrs old");
 }
 else
 {
 System.out.println("Access granted.you are old enough");
 }
 }
 public static void main(String args[])
 {
 checkAge(15);
 }
 }
