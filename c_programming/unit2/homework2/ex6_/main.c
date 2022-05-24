/*
 * main.c
 *
 *  Created on: May 24, 2022
 *      Author: soft
 */


// program to calculate sum of naturals numbers
#include<stdio.h>

int main (){
	unsigned num,sum=0;
	printf("Enter an integer:");
	fflush(stdout);
	scanf("%d",&num);
	for(int i=1;i<=num;i++){
		sum+=i;
	}
	printf("sum =%d",sum);
}
