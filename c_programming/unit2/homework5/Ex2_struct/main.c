#include <stdio.h>
#include <stdlib.h>
//program to add two distances (in inch-feet)system using structure
struct SDistances
{
    int feet;
    float inch;

}distance,sum;
struct SDistances Read_data(char data[]){

    printf("Enter information for %s \n",data);
    printf("Enter feet:");
    scanf("%d",&distance.feet);
    printf("Enter distance inch:");
    scanf("%f",&distance.inch);
    return distance;


}
struct SDistances Add_data(struct SDistances n1,struct SDistances n2){

    sum.feet=n1.feet+n2.feet;
    sum.inch=n1.inch+n2.inch;
    if(sum.inch>12.0){
        sum.inch=sum.inch-12.0;
        ++sum.feet;
    }
    return sum;


}
void print(char n[],struct SDistances c){
    printf("%d\'-%.1f\"",c.feet,c.inch);


}
int main()
{
    struct SDistances A,B,c;
    A=Read_data("1st");
    B=Read_data("2nd");
    c=Add_data(A,B);
    print("sum of distances=",c);

    return 0;
}
