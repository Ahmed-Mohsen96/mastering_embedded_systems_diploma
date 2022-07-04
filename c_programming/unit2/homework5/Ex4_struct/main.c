#include <stdio.h>
#include <stdlib.h>
//program to store information of students (name,roll and marks)of student using structure
struct S_student
{
    char name[100];
    int roll;
    float marks;
};

int main()
{
    struct S_student students[10];
    int i;

    printf("Enter information of students\n");
    for(i=0;i<10;i++){
        printf("Enter name:");
        scanf("%s",&students[i].name);
        printf("Enter roll number:");
        scanf("%d",&students[i].roll);
        printf("Enter mark:");
        scanf("%f",&students[i].marks);
    }
    printf("\ninformation\n");
    for(i=0;i<10;i++){
       printf("roll:%d\n",students[i].roll);
       printf("name:%s\n",students[i].name);
       printf("mark :%.2f\n",students[i].marks);
    }


    return 0;
}
