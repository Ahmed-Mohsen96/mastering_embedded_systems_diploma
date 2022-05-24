/*
 * main.c
 *
 *  Created on: May 24, 2022
 *      Author: soft
 */

// making calculator

#include<stdio.h>

int main(){
	char operator;
	float a,b;

	printf("Enter an operator:");
	fflush(stdout);
	scanf("%c",&operator);
	printf("Enter two numbers");
	fflush(stdout);
	scanf("%f%f",&a,&b);
	switch(operator){
	case '+':
		printf("sum=%f\n",a+b);
		break;
	case '-':
		printf("sub=%f\n",a-b);
		break;
	case '*':
		printf("mulitple =%f",a*b);
		break;
	default:
		printf("not exist");
	}
}
