#include <stdio.h>
#include <stdlib.h>
//program to store information (name,roll and marks)of student using structure
struct S_student
{
    char name[100];
    int roll;
    float marks;
}student;

int main()
{
    printf("Enter information of student\n");
    printf("Enter name:");
    scanf("%s",student.name);
    //gets(student.name);
    printf("Enter roll number:");
    scanf("%d",&student.roll);
    printf("Enter mark:");
    scanf("%f",&student.marks);
    printf("information\n");
    printf("name:%s\n",student.name);
    printf("roll:%d\n",student.roll);
    printf("mark :%.2f\n",student.marks);

    return 0;
}
