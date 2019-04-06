#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main() {
	pid_t returnedValue = fork();
	if(returnedValue < 0) {
		perror("error forking");
		return -1;
	} else if (returnedValue == 0){
		if(close(STDIN_FILENO) < 0){
	             perror("error closing standard output");
	              return -1;
	          }
		if(open("/etc/passwd", O_RDONLY) < 0){
			perror("error opening file");
			return -1;
		}
		
		execlp("tr", "tr", "a-z", "A-Z", NULL);
		perror("error executing tr");
		return -1;
	} else {
		if(waitpid(returnedValue, 0, 0) < 0) {
			perror("error waiting for child");
			return -1;
		}
	}
}

	
