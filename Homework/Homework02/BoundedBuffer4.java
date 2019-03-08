public class BoundedBuffer {
    private Object[] buffer = new Object[5];
    private int numOccupied = 0;
    private int firstOccupied = 0;

    public synchronized void insert(Object o) throws InterruptedException {
        while (numOccupied == buffer.length) {
            wait();
        }
        buffer[(firstOccupied + numOccupied) % buffer.length] = o;
        if ( numOccupied == 0 ) {
            notifyAll();
        }
        numOccupied++;
    }

    public synchronized Object retrieve() throws InterruptedException {
        while (numOccupied == 0) {
            wait();
        }
        Object retrieved = buffer[firstOccupied];
        buffer[firstOccupied] = null;
        firstOccupied = (firstOccupied + 1) % buffer.length;
        if ( numOccupied == buffer.length ) {
            notifyAll();
        }
        numOccupied--;
        notifyAll();
        return retrieved;
    }

    public void printBuffer() {
        System.out.print("buffer: " );
        for ( Object a : buffer ) {
            System.out.print( a + " " );
        }
        System.out.println();
    }

    public int getBufferLength() {
        return buffer.length;
    }

    public class ProducingThread extends Thread {
        public void run() {
            System.out.println( "Producer has launched" );
            try {
                while ( numOccupied < buffer.length ) {
                    int number = (int)Math.floor(Math.random() * 101);
                    insert(number);
                    System.out.println( "Producer added " + number + " to buffer." );
                        System.out.println( "Producer is sleeping..." );
                    Thread.sleep(323);
                }
            } catch (Exception e) {
                System.out.println( "Buffer is full" );
            }

            System.out.println( "Producer is done." );

        }
    }

    public class ConsumingThread extends Thread {
        public void run() {
            System.out.println( "Consumer has launched" );
            try {
                System.out.println( "Consumer has launched" );
                while ( numOccupied > 0 ) {
                    Object o = retrieve();
                    System.out.println( "Consumer has taken item " + o );
                    Thread.sleep(400);
                }
            } catch (Exception e) {
                System.out.println( "Consumption was interrupted" );
            }
            System.out.println( "Consumer is done." );
        }
    }

    public void testBuffer() {
        ProducingThread p = new ProducingThread();
        ConsumingThread c = new ConsumingThread();

        System.out.println( "___________Testing BoundedBuffer___________" );
        System.out.println( "Producer should fill the buffer to capacity and the consumer should completely empty it.\n" );
        p.start();
        c.start();
    }

    public static void main (String args[]) {
        BoundedBuffer b = new BoundedBuffer();
        b.testBuffer();
    }

 }
