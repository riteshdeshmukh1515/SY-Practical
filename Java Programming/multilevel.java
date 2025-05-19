class multilevel{
    public static void main(String[] args) {
       // child obj= new child();
       // obj.disp();
       // inherit obj1=new inherit();
       // obj.display();
       grandchild object=new grandchild();
       object.display();
       object.display1();
       object.display2();
    }

}
 class inherit {
    public
    void display()
    {
        System.out.println("this is parent class");
    }
}
class child extends inherit{
      void display1()
      {
        System.out.println("this is child class");
      }
 } 

 class grandchild extends child{
    void display2(){
        System.out.println("this is grand child");;
    }
 }
