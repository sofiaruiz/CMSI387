#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] ) {
    #define NUMBER_OF_SQUARES 21

    int odds = 0;
    for ( int i = -10; i < 11; i++ ) {
        int square = i * i;
        if ( square % 2 != 0 ) {
            printf("%d\t%d\t%s\n" , i , square, "ODD");
            odds++;
        }
        else {
            printf("%d\t%d\t%s\n" , i , square, "EVEN");
        }
    }
    printf("\n# odd numbers = %d \n# even numbers = %d" , odds , NUMBER_OF_SQUARES - odds);

}
