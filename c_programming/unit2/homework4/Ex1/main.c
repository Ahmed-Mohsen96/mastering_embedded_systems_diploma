/*
 * main.c
 *
 *  Created on: Jun 16, 2022
 *      Author: soft
 */

#include<stdio.h>
//prime numbers bet 2 intervals by user defined function
void prime_nums(int num);


int main()
{
	int x,y;
	int i=0;

	printf("Enter two number 'intervals':");
	fflush(stdout);
	scanf("%d%d",&x,&y);
	printf("prime nums bet %d and %d are:",x,y);
	for(i=x;i<=y;i++){
		prime_nums(i);

	}

	return 0;
}
void prime_nums(int num){

	if((num%2==0)||(num%3==0||(num%5==0))){
		return 0;
	}
	else
	{

		printf("%d ",num);

	}
}

