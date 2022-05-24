/*
 * main.c
 *
 *  Created on: May 24, 2022
 *      Author: soft
 */


#include<stdio.h>

int main(){
	// program to check if num is positive or negitive
	float num;
	printf("Enter a number You want to check");
	fflush(stdout);
	scanf("%f",&num);
	if(num>=0){
		if(num==0){
			printf(" num is Zero");
		}
		printf("num is positve");
	}
	else
		printf("num is negetive");

}
