class Multi1 implements Runnable {
    public void run() {
        System.out.println("Thread 1 is running");
    }

    public static void main(String args[]) {
        Multi1 obj = new Multi1();
        Multi obj1 = new Multi();

        Thread t1 = new Thread(obj);  
        Thread t2 = new Thread(obj1); 

        t1.start(); 
        t2.start(); 
    }
}

class Multi implements Runnable {
    public void run() {
        System.out.println("Thread 2 is running");
    }
}

