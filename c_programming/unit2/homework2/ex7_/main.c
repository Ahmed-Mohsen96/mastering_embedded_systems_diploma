/*
 * main.c
 *
 *  Created on: May 24, 2022
 *      Author: soft
 */

// c program to find factorial of number

#include<stdio.h>

int main(){
	int num;
	unsigned long int factorial=1;
	printf("Enter an integer number:");
	fflush(stdout);
	scanf("%d",&num);
	if(num<0){
		printf("negetive num not accepted\n");

	}
	else{
		for(int i=1;i<=num;i++){
			factorial*=i;
		}
		printf("factorial=%lu",factorial);
	}
}
