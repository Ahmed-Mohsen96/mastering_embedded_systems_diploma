/*
 * main.c
 *
 *  Created on: Jun 3, 2022
 *      Author: soft
 */

#include<stdio.h>

int main()
{
	// program to insert specific element in array
	int arr[10],num,elem,loc,i;
	printf("Enter no of element:");
	fflush(stdout);
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		fflush(stdout);
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<num;i++){
		printf("%d\t",arr[i]);
	}
	printf("\nEnter element wanted to insert:");
	fflush(stdout);
	scanf("%d",&elem);
	printf("Enter location:");
	fflush(stdout);
	scanf("%d",&loc);
	// make a space to new element
	for(int i=num;i>=loc;i--){
		arr[i]=arr[i-1];
	}
	// stretch array
	num++;
	// set new element to location
	arr[loc-1]=elem;

	for(i=0;i<num;i++){
		printf("%d\t",arr[i]);
		}


return 0;
}
