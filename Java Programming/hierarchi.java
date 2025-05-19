class hierarchi{
    public static void main(String[] args) {
        child1 obj= new child1();
        obj.display();
        obj.display1();
        child2 obj2= new child2();
        obj2.display();
        obj2.display2();
        
    }

}
 class inherit {
    public
    void display()
    {
        System.out.println("this id parent class");
    }
}
class child1 extends inherit{
      void display1()
      {
        System.out.println("1st child class");
      }
 } 
 class child2 extends inherit{
    void display2()
    {
      System.out.println("2nd child class");
    }
} 
