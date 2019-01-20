#include <stdio.h>
#include <stdlib.h>

   int main( int argc, char * argv[] ) {
       char   name[100];
       printf( "Enter a name: " );
       scanf("%s",name);

       printf( "Hello, %s \n\n\n",name );
   }
