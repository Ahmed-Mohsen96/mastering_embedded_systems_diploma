/*
 * main.c
 *
 *  Created on: May 22, 2022
 *      Author: Ahmed mohsen
 */


#include <stdio.h>



int main()
{

	float a,b,temp ;
	printf("#########console-output###\n");
	printf("Enter a value of a:");
	fflush(stdout);
	scanf("%f",&a);
	printf("Enter a value of b:");
	fflush(stdout);
	scanf("%f",&b);
	temp=a;
	a=b;
	b=temp;
	printf("After swapping value of a=%f",a);
	printf("After swapping value of b=%f",b);
	printf("\n######################\n\n");
	printf("######################################################\n#########################################");




}
