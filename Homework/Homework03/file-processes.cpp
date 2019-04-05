#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main() {
if(open("/etc/passwd", STDIN_FILENO) < 0){
	perror("error opening /etc/passwd");
	return -1;
    }

    execlp("tr", "tr", "a-z", "A-Z", NULL);
    perror("error executing tr");
    return -1;
}

	
