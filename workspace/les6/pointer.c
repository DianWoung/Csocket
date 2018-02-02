#include <stdio.h>

void change(int *a, int *b)
{
    *a = *a * 2;
    *b = *b * 2;
}

int main(int argc, char *argv[])
{
    int a = 5;
    int b = 3;
    change(&a, &b);
    printf("a  == %d \n b == %d \n", a, b);
    return 0;
}