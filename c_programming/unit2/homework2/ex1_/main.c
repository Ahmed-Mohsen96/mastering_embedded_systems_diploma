/*
 * main.c
 *
 *  Created on: May 24, 2022
 *      Author: soft
 */

#include <stdio.h>

int main()
{
	// program to check even or odd
	int num;
	printf("Enter an integer you want to check:");
	fflush(stdout);
	scanf("%d",&num);
	if(num%2==0)
	{
		printf("%d is even\n",num);
	}
	else
		printf("%d is odd\n",num);



	return 0;
}
