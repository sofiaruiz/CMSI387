#include <stdio.h>
 #include <stdlib.h>
 #include <pthread.h>


  int mutex = 1;
  int full  = 0;
  int empty = 7;          // maximum of seven messages in buffer
  int x     = 0;
  int buffer[7];

  static void *run_producer(void *ignored){
      while (1){
          sleep(.5);
          producer();
          mutex
      }
      return NULL;
  }

  static void *run_consumer(void *ignored){
      while (1){
          sleep(.5);
          consumer();
      }
      return NULL;
  }

  int main()
  {
     int n;
     void producer();
     void consumer();
     int wait( int );
     int signal( int );

     while( 1 ) {
        producer();
        consumer();
     }
     return 0;
  }

  int wait( int s ) {
     return( --s );
  }

  int signal( int s ) {
     return( ++s );
  }

  void producer() {
     while(1) {
         sleep(.5);
         mutex = wait( mutex );
         full  = signal( full );
         empty = wait( empty );
         x++;
         printf( "\n  Producer produces the item %d", 1 );
         mutex = signal( mutex );
     }
  }

  void consumer()
  {
     while(1) {
         sleep(.5);
         mutex = wait( mutex );
         full  = wait( full );
         empty = signal( empty );
         printf( "\n  Consumer consumes item %d", 1 );
         x--;
         mutex = signal( mutex );
     }
  }
