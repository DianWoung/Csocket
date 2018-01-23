#include <stdio.h>

int main(int argv, char *argc[])
{
	printf("argv num is %d\n", argv);
	int i;
	for (i = 0; i < argv; i++)
	{
		printf("argc[%d] is %s\n", i, argc[i]);
	}
	printf("Hello World!\n");
	return 0;
}


