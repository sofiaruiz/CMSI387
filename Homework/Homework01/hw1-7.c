#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] ) {

    char name[25];
    printf( "Enter your name: ");
    gets(name);
    char age[10];
    printf("Enter your age: ");
    gets(age);
    char year[25];
    printf("Enter your class year: ");
    gets(year);
    char hometown[25];
    printf("Enter your hometown: ");
    gets(hometown);
    char major[25];
    printf("Enter your major: ");
    gets(major);
    char food[25];
    printf("Enter your favorite food: ");
    gets(food);

    printf( "\nName: %s\nAge: %s\nClass Year: %s\nHometown: %s\nMajor: %s\nFavorite Food: %s\n", name,age,year,hometown,major,food);
    exit( 0 );

}
