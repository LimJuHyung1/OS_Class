#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	pid_t pid;

	pid = fork(); // 자식 프로세스 생성

	if (pid > 0) { // 부모 프로세스 코드
		printf("부모프로세스: fork()의 리턴 값 = 자식프로세스 pid = %d\n", pid);
		printf("부모프로세스: 프로세스 pid = %d\n", getpid());
		wait(NULL); // 자식프로세스가 종료할 때까지 대기 
		printf("Hello\n");
		return 0;
	}
	else if (pid == 0) { // 자식 프로세스 코드
		printf("자식프로세스: fork()의 리턴 값 pid = %d\n", pid);
		printf("자식프로세스: pid = %d, 부모프로세스 pid = %d\n", getpid(), getppid());
		execlp("/bin/ls", "ls", "-l", NULL); // /bin/ls를 현재프로세스에 오버레이하여 실행
	}
	else { // fork() 오류
		printf("fork 오류");
		return 0;
	}
}
