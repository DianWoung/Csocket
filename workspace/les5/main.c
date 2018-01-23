#include <stdio.h>

int main()
{
	printf("Hello world\n");
	int a, b;
	puts("Please input the num a:\n");
	scanf("%d", &a);
	puts("Please input the num b:\n");
	scanf("%d", &b);
	if (0 != b) {
		printf("%d + %d = %d\n", a, b, a+b);
	} else {
		fprintf(stderr, "input num b must not equal 0\n");
		return 1;
	}
	return 0;
}
