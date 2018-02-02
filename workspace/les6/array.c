#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 3;
	int b = 2;
	int array[3];
	int *arr = array;
	arr[0] = 1;
	arr[1] = 10;
	arr[2] = 100;
	int *p = &a;
	// p += 5;
	// *p = 101;
	// p = &a;
	p[5] = 101;
	int i;
	for (i = 0; i < 6; i++){
		printf("*p = %d\n", *p);
		p ++;
	}
	printf("--------------------------\n");
	p = &a;
	for (i = 0; i < 6; i++){
		printf("p[%d] = %d\n", i, p[i]);
	}
	return 0;
}
	
	
