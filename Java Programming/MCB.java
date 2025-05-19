//program of multiple catch block exception handling example
 public class MCB
 {
  public static void main(String[] args)
  {
   try{
    int a[]=new int[5];
    a[5]=30/0;
    }
    catch(ArithmeticException e)
    {
    System.out.println("Arithmetic Exceptrion occurs");
    }
    catch(ArrayIndexOutOfBoundsException e)
    {
    System.out.println("Array out of bound exception occurs");
    }
    catch(Exception e)
    {
    System.out.println("Parent Exception occurs");
    }
    System.out.println("rest of the code");
    }
 }
