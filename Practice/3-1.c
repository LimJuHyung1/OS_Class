#include <stdio.h>
#include <stdlib.h>

int a = 10;
void f(){
	int c = 30;
	printf("%d\n", c);
}
int main(void){
	int b = 20;
	int *p = (int*)malloc(100);
	f();
	printf("%d\n", b);
	return -1;
}
