#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int a[4] = {1,2,3,4}; int b[4];
void *func1() {
b[0] = a[0] + 1; b[1] = a[1] + 1;
printf("In func1: %d\n", b[0]);
}
void *func2() {
b[2] = a[2] + 1; b[3] = a[3] + 1;
printf("In func2: %d\n", b[2]);
}
int main(void) {
int pid;
// child 프로세스를 생성하여 func1()을 수행
if ((pid = fork()) < 0)
exit(1);
else if (pid == 0) {
func1();
exit(0);
}
wait();
func2();
printf("sum=%d\n", b[0]+b[1]+b[2]+b[3]);
exit(0);
}

