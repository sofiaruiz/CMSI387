#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main( int argc, char * argv[] ) {

   int array_size = atoi(argv[1]);
   int * array = malloc(sizeof(int)*array_size);
   clock_t start, end;
   int length = (array_size / 4096) + 1;
   double times[length];
   double cpu_time_used;
   double sumOfTimes = 0.0;
   double average; 

   printf( "Size: %d\n", array_size);
   srand(23);
   for (int i = 0; i < array_size; i+=1) {
       array[i] = (rand() % 100) + 1;
   }
   

   for (int i = 0; i < array_size; i+= 4096) {
       start = clock();
       array[i];
       end = clock();
       cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC;
       times[i / 4096] = cpu_time_used;

   }

   for (int i = 0; i < length; i+=1) {
       printf("times[%d]: %fs\n", i, times[i]);
       sumOfTimes += times[i];
   }
   average = sumOfTimes / (double) length;
   printf( "Average time: %fs\n", average);

   free(array);
   return 0;
}


   

