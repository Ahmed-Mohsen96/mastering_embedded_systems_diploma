#include <stdio.h>
#include <stdlib.h>
union U_Empolyee
{
    char name[32];
    float salary;
    int empolyee_no;
}u;
struct S_Empolyee
{
    char name[32];
    float salary;
    int empolyee_no;
}s;

int main()
{
    printf("size of union=%d\n",sizeof(u)); //32
    printf("size of structure=%d",sizeof(s));//40


    return 0;
}
