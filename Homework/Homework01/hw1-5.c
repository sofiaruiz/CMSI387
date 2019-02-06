#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

static void *second(void *ignored){
    while (1){
        sleep(5);
        printf("\nSecond thread slept 5 seconds.\n");
    }
    return NULL;
}

int main(int argc, char *argv[]){
    pthread_t second_thread;
    int code;

    code = pthread_create(&second_thread, NULL, second, NULL);
    if(code){
        fprintf(stderr, "pthread_create failed with code %d\n", code);
    }

    int key = 0;
    printf("Press some keys: ");
    while (key != 10) {
        key = fgetc(stdin);
    }
    pthread_cancel(second_thread);
    printf("Second thread has been canceled.\n");
    return 0;
}

// The sleeping thread can print its periodic messages while the main thread waits for keyboard input.
// The main thread cannot read input, kill the sleeping thread, and print a message while the sleeping thread is in the early part of one of its five-second sleeps but it can appear to do so because of how fast the operating system switches threads.
