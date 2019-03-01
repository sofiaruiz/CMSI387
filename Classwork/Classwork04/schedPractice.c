#include <stdio.h>
#include <stdlib.h>

int allDone( char * argv[] ) {
    for ( int i = 2; i < sizeof(argv); i+=2 ) {
        if ( argv[i] != 0 ) {
            return 0;
        }
    }
    return 1;
}

int main( int argc, char * argv[] ) {
    printf('%i', allDone(argv));
}
