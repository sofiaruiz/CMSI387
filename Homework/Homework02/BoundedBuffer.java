//TODO: reduce the size of the buffer
// TODO: Second, you need a test program that has multiple threads doing insertions and retrievals, with some way to see the diﬀerence between when each operation is started and when it completes
//TODO: need to see that the retrieved values are correct.

public class BoundedBuffer {
    private Object[] buffer = new Object[5];
    private int numOccupied = 0;
    private int firstOccupied = 0;

    public synchronized void insert(Object o) throws InterruptedException {
        System.out.println( "numOccupied: " + numOccupied + " buffer.length: " + buffer.length);
        while (numOccupied == buffer.length) {
            wait();
            buffer[(firstOccupied + numOccupied) % buffer.length] = o;
            numOccupied++;
            notifyAll();
        }
        // what I think it is missing:
        buffer[(firstOccupied + numOccupied) % buffer.length] = o;
        numOccupied++;

    }

    public synchronized Object retrieve() throws InterruptedException {
        while (numOccupied == 0) {
            wait();
            Object retrieved = buffer[firstOccupied];
            buffer[firstOccupied] = null;
            firstOccupied = (firstOccupied + 1) % buffer.length;
            numOccupied--;
            notifyAll();
            return retrieved;
        }
        return -1;
    }

    public void printBuffer() {
        System.out.print("buffer: " );
        for ( Object a : buffer ) {
            System.out.print( a + " " );
        }
        System.out.println();
    }
 }
