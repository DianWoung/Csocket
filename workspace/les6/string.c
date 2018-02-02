#include <stdio.h>

int main(int argc, char *argv[])
{
    char str[] = "hello";
    char *str2 = "World";
    char str3[10];
    printf("Input the value \n");
    scanf("%s", str);

    printf("str is %s\n", str);
    printf("str2 is %s\n", str2);
    printf("str3 is %s\n", str3);
    return 0;
}