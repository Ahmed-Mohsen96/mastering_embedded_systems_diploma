/*
 * main.c
 *
 *  Created on: May 22, 2022
 *      Author: Ahmed mohsen
 */


#include <stdio.h>



int main()
{

	float a,b ;
	printf("#########console-output###\n");
	printf("Enter a value of a:");
	fflush(stdout);
	scanf("%f",&a);
	printf("Enter a value of b:");
	fflush(stdout);
	scanf("%f",&b);
	a=a+b;
	b=a-b;
	a=a-b;

	printf("After swapping value of a=%f\n",a);
	printf("After swapping value of b=%f",b);
	printf("\n######################\n\n");
	printf("######################################################\n#########################################");




}
