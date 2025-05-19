//program of exception handleing
class TCEX
{
  public static void main(String[] args)
   {
    try
     {
       int a=10, b=5, c=5;
       int x;
       x=a/(b-c);
       System.out.println("the value of x is "+x);
      }
    catch(Exception e)
     {
       System.out.println("caught an exception:"+e.getMessage());
     }
     System.out.println("End of program");
   }
}

