#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	pid_t pid;
	int i, sum=0;

	pid = fork(); // 자식프로세스 생성 
	if (pid > 0) { // 부모 프로세스에 의해 실행되는 코드  
		printf("부모프로세스: fork()의 리턴 값 = 자식프로세스 pid = %d\n", pid);
		printf("부모프로세스: pid = %d\n", getpid());
		wait(NULL); // 자식프로세스가 종료할 때까지 대기
		printf("부모프로세스종료\n");
		return 0;
	}
	else if (pid == 0) { // 자식 프로세스에 의해 실행되는 코드  
		printf("자식프로세스: fork()의 리턴 값 pid = %d\n", pid);
		printf("자식프로세스: pid = %d, 부모프로세스 pid = %d\n", getpid(), getppid());
		sum = 0;
		for (i=1; i<=100; i++)
			sum += i;
		printf("자식프로세스: sum = %d\n", sum);	
		return 0;
	}
	else { // fork() 오류 
		printf("fork 오류");
		return 0;
	}
}

