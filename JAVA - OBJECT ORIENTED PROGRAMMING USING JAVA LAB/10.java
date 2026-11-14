// Multi Threading By Thread Class and Runnable Interface 
// Make 2 threads one printing the odd numbers from 1 to 100 and another thread printing 100 to 1.  Demonstrate its working using extend Thread class and Runnable Interface.
class OddNumberThread extends Thread {
    @Override
    public void run() {
        for (int i = 1; i <= 100; i += 2) {
            System.out.println("[Thread class] Odd number: " + i);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted");
            }
        }
    }
}
class ReverseNumberThread extends Thread {
    @Override
    public void run() {
        for (int i = 100; i >= 1; i--) {
            System.out.println("[Thread class] Reverse number: " + i);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted");
            }
        }
    }
}
class OddNumberRunnable implements Runnable {
    @Override
    public void run() {
        for (int i = 1; i <= 100; i += 2) {
            System.out.println("[Runnable interface] Odd number: " + i);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.out.println("Runnable interrupted");
            }
        }
    }
}
class ReverseNumberRunnable implements Runnable {
    @Override
    public void run() {
        for (int i = 100; i >= 1; i--) {
            System.out.println("[Runnable interface] Reverse number: " + i);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.out.println("Runnable interrupted");
            }
        }
    }
}
class MultiThreadingMain {
    public static void main(String[] args) {
        try {
            OddNumberThread oddNumberThread = new OddNumberThread();
            ReverseNumberThread reverseNumberThread = new ReverseNumberThread();
            oddNumberThread.start();
            reverseNumberThread.start();
            oddNumberThread.join();
            reverseNumberThread.join();
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted");
        }
        try {
            Thread oddNumberRunnableThread = new Thread(new OddNumberRunnable());
            Thread reverseNumberRunnableThread = new Thread(new ReverseNumberRunnable());
            oddNumberRunnableThread.start();
            reverseNumberRunnableThread.start();
            oddNumberRunnableThread.join();
            reverseNumberRunnableThread.join();
        } catch (InterruptedException e) {
            System.out.println("Runnable interrupted");
        }
    }
}