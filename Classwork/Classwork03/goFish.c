#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] ) {

   char input[25];
   int number;
   int index = 0;
   int sum = 0;
   float average = 0;

   while ( 1 ) {
       printf( "Enter a number: " );
       number = atoi( gets( input ) );
       if ( number == -9999 ) {
           break;
       }
       // input[index] = number;
       sum += number;
       printf("%d\n", sum );

       index++;
       average = sum / (index);
   }

   printf( "Sum: %d\nAverage: %f\n", sum, average);
   exit( 0 );

}
