public class BoundedBufferTests {

    private static BoundedBuffer b = new BoundedBuffer();

    public static void thread1() {
        Thread t1 = new Thread();
        System.out.println( "Thread 1 has begun." );
        try {
            b.insert(1);
        } catch (Exception e) {
            System.out.println( "Could not insert 1" );
        }
        try {
            b.insert(2);
        } catch (Exception e) {
            System.out.println( "Could not insert 12" );
        }
        System.out.println( "Thread 1 is sleeping for 5 seconds" );
        thread2();
        try {
            t1.sleep(5000);
        } catch (Exception e) {
            System.out.println( e );
        }
        try {
            b.insert(3);
        } catch (Exception e) {
            System.out.println( "Could not insert 3" );
        }
        try {
            b.insert(4);
        } catch (Exception e) {
            System.out.println( "Could not insert 4" );
        }
        System.out.println( "Thread 1 is complete" );
        b.printBuffer();
    }

    public static void thread2() {
        Thread t1 = new Thread();
        System.out.println( "Thread 2 has begun." );
        try {
            b.insert(10);
        } catch (Exception e) {
            System.out.println( "Could not insert 10" );
        }
        try {
            b.insert(20);
        } catch (Exception e) {
            System.out.println( "Could not insert 20" );
        }
        System.out.println( "Thread 2 is sleeping for 1 second" );
        try {
            t1.sleep(1000);
        } catch (Exception e) {
            System.out.println( e );
        }
        try {
            b.insert(30);
        } catch (Exception e) {
            System.out.println( "Could not insert 30" );
        }
        try {
            b.insert(40);
        } catch (Exception e) {
            System.out.println( "Could not insert 40" );
        }

        System.out.println( "Thread 2 is complete" );
        b.printBuffer();
    }

    public static void thread3() {

    }

    public static void main(String args[]) {
        // try {
        //     b.insert(1);
        // } catch (Exception e) {
        //     System.out.println( "Could not insert 1" );
        // }
        // b.printBuffer();

        thread1();
        b.printBuffer();
        // thread2();
        // b.insert(1);
        // b.retrieve();
    }
}
