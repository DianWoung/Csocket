#include <stdio.h>
union data{
    int a;
    char b;
    int c;
};
int main(){
    union data msg;
    msg.a = 12;
    msg.b = 'C';
    msg.c = 11;
    printf("msg  a = %c\n", msg.b);
    printf("%p\n%p\n%p\n", &msg.a,&msg.b,&msg.c);
    return 0;
}