/**
 * 函数指针的学习(本程序不在书籍的讨论范围，只是自己的练习脚本)
 */
#include <stdio.h>

int max(int x, int y){return (x > y ? x:y);}
typedef int (*ptr_func)(int, int);

int add1(int a1, int b1);
int add2(int a2, int b2);

int main()
{
    
    int a, b, c;
    ptr_func ptr = max;
    scanf("%d%d", &a, &b);
    c = (*ptr)(a, b);
    printf("a = %d, b = %d, max = %d\n", a, b, c);


    int numa1 = 1, numa2 = 2;
    int numb1 = 2, numb2 = 3;
    int(*op[2])(int a, int b);
    op[0] = add1;
    op[1] = add2;
    printf("%d%d\n", op[0](numa1, numb1), op[1](numa2, numb2));
    return 0;
}

int add1(int a1, int b1)
{
    return a1 + b1;
}

int add2(int a2, int b2)
{
    return a2 + b2;
}