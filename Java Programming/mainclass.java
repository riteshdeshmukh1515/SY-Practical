class mainclass{
    public static void main(String[] args) {
        child obj= new child();
        obj.disp();
       // inherit obj1=new inherit();
        obj.display();
    }

}
 class inherit {
    public
    void display()
    {
        System.out.println("this id parent class");
    }
}
class child extends inherit{
      void disp()
      {
        System.out.println("child class");
      }
 } 
