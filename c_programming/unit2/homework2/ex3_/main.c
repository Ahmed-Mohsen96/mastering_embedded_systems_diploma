/*
 * main.c
 *
 *  Created on: May 24, 2022
 *      Author: soft
 */

#include <stdio.h>

int main()
{
	//program to find biggest number from three numbers
	float a,b,c;
	printf("Enter three numbers");
	fflush(stdout);
	scanf("%f%f%f",&a,&b,&c);
	if(a>b){
		if(a>c){
			printf("largest num is %f",b);
		}
		else
			printf("largesr num is %f",c);
	}
	else if(b>a){
		if(b>c){
			printf("largest num is %f",b);
		}
		else
			printf("largest is %f",c);
	}
}
