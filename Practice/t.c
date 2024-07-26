#include <stdio.h>

int main(void) {
	int a, b;
	double div;
	char op = '_';
	
	printf("프로그램 종료는 ?를 입력하시면 됩니다.\n");
	printf("\n-------------------------------------------------\n");

	while (1) {		
		printf("\n두 숫자를 입력해주세요 : ");
		scanf("%d %d", &a, &b);

		printf("\n연산자를 입력해주세요 : ");
		getchar();
		op = getchar();

		if (op == '?' ) break;
		
		switch (op) {
		case '+':
			printf("\n----\n");
			printf("%d\n", a + b);
			printf("----\n");
			break;
		case '-':
			printf("\n----\n");
			printf("%d\n", a - b);
			printf("----\n");
			break;
		case '*':
			printf("\n----\n");
			printf("%d\n", a * b);
			printf("----\n");
			break;
		case '/':
			div = a / b;
			printf("\n----\n");
			printf("%f\n", (double)a / b);
			printf("----\n");
			break;

		default:
			printf("잘못 입력하셨습니다.\n이 프로그램을 마치려면 ?를 입력해주세요.\n");
			break;
		}
		
	}

}

