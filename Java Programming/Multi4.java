class Multi4 extends Thread {
    public void run() {
        System.out.println("Thread 1 is running");
    }

    public static void main(String args[]) {
        Multi4 t1 = new Multi4();  
        Multi2 t2 = new Multi2();  

        t1.start();  
        t2.start();  
    }
}

class Multi2 extends Thread {
    public void run() {
        System.out.println("Thread 2 is running");
    }
}

