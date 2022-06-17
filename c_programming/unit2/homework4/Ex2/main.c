/*
 * main.c
 *
 *  Created on: Jun 16, 2022
 *      Author: soft
 */

#include<stdio.h>

// function to calculate factorial by recursion
int factorial(int i){
	/*static int j=1,sum=1;
	while(j<=i){
		sum*=j;
		j++;
		if(j<=i){
			factorial(j);
		}

	}
	return sum;*/
	if(i!=1)
		return i*factorial(i-1);
}

int main()
{
	int num;
	printf("Enter a number :");
	fflush(stdout);
	scanf("%d",&num);
	printf("factorial of %d is :%d",num,factorial(num));

	return 0;
}
