/*
 * main.c
 *
 *  Created on: Jun 3, 2022
 *      Author: soft
 */

#include <stdio.h>

int main()
{
	// program to calculate averege of numbers using array
	float arr[10],average,sum=0;
	int i,data;
	printf("Enter the number of data:");
	fflush(stdout);
	scanf("%d",&data);
	for(i=0;i<data;i++){
		printf("%d:Enter number:\n",i+1);
		fflush(stdout);
		scanf("%f",&arr[i]);
		sum+=arr[i];
	}
	average=sum/data;
	printf("average=%0.2f\n",average);

}
