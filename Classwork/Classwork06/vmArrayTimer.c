#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main( int argc, char * argv[] ) {

   int array_size = atoi(argv[1]);
   int * array = malloc(sizeof(int)*array_size);
   clock_t start, end;
   double cpu_time_used;

  start = clock();

   printf( "Size: %d\n", array_size);
   srand(23);
   for ( int i = 0; i < array_size; i++ ) {
       array[i] = (rand() % 100) + 1;
   }
   end = clock();
   cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC;
   printf( "Element[4095]: %d\n", array[4095]);
   printf( "Time: %s\n", cpu_time_used);
   free(array);
   exit( 0 );
}
