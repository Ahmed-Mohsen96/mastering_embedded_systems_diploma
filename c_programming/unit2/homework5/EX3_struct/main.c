#include <stdio.h>
#include <stdlib.h>


//program to add two complex number py passing structure to function
struct Scomplex
{
    double m_R;
    double m_I;
}complexx;
struct Scomplex Read_complex(char name[]){

    printf("Enter %s(real and imaginary):",name);
    scanf("%lf%lf",&complexx.m_R,&complexx.m_I);
    return complexx;



}
struct Scomplex Add_complex(struct Scomplex A,struct Scomplex B){

    struct Scomplex sum;
    sum.m_R=A.m_R+B.m_R;
    sum.m_I=A.m_I+B.m_I;
    return sum;

};
void print_complex(char name[],struct Scomplex sum){

    printf("%s =(%.2lf) + j (%.2lf)\n ",name,sum.m_R,sum.m_I);


}

int main()
{
    struct Scomplex X,Y,Z;
    X=Read_complex("First Number");
    Y=Read_complex("Second Number");
    Z=Add_complex(X,Y);
    print_complex("sum",Z);

    return 0;
}
