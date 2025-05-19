//java program for calculating salary
class salary{
    public static void main(String args[])
   {
   double basicSalary, grossSalary;
   double tax;
   double pension;
   double medical;
   basicSalary=600000.00;
   tax=basicSalary*0.50;
   pension=6000.60;
   medical=pension/2;
   grossSalary=basicSalary-tax-pension-medical;
   System.out.println("the gross salary is \t" +grossSalary);
   }
}   
