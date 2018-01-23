#include <stdio.h>

int main()
{
	printf("Hello World!");
	int a;
	scanf("%d", &a);
	printf("input value is : %d\n", a);
	fprintf(stdout, "please input the value b :\n");
	int b;
	fscanf(stdin, "%d", &b);
	if (b < 0) {
		fprintf(stderr,"the value must > 0\n");
		return 1;
	}
	return 0;
}

