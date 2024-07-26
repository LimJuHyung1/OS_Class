#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int glob = 6;
int main(){
	pid_t pid;
	int var = 88;
	printf(" Before fork() \n");
	if((pid = fork()) < 0){
		printf(" fork() error! \n");
			}
	else if (pid == 0) {	//child
		glob++;
		var++;
	}
	else
		sleep(2);	//parent
	printf(" pid = %d, glob = %d, var = %d \n", getpid(), glob, var);
	exit(0);
	

}
