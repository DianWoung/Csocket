#include <stdio.h>
#define R 10
#define N(n) n*10
#define ADD(a,b) (a+b)

typedef int intger;
typedef int * ptr;

struct student{
    char name[20];
    int age;
    int tall;
};

int main(int argc, char *argv[])
{
    struct student xiaoming = {
        "XiaoMing",
        22,
        180,
    };
    struct student classmates[2] = {
        {
            "Wang",
            29,
            178,
        },
        {
            "Dian",
            22,
            167,
        }
    };
	int a = R;
    ptr q = NULL;
    struct student *stu;
    struct student *arr;
    arr = &classmates;
    arr->age = 11;
    arr++;
    arr->age = 33;
    stu = &xiaoming;
    stu->age = 19;
   (*stu).tall = 188;
    printf("Hello world a*N = %d, a+b = %d\n", N(a), ADD(a,a));
    printf("%s's age is %d, %d tall\n", (*stu).name,xiaoming.age,xiaoming.tall);
    printf("%s's age is %d,%s's age is %d\n", classmates[0].name,classmates[0].age,classmates[1].name,classmates[1].age);
    return 0;
}
