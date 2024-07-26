#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid;
	char *message;
	int n;
	printf(" fork program starting! \n");
	pid = fork();
	switch (pid){
		case -1:
			printf("fork failed \n");
			exit(1);
		case 0:
			message = "This is child process";
			n = 5;
			break;
		default:
			message = "This is parent process";
			n = 3;
			break;}
	for(;n>0;n--){
		puts(message);
		if(pid == 0)
			sleep(2);
		else
			sleep(1);}
	exit(0);
}
