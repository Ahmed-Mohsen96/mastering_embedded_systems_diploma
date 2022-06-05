/*
 * main.c
 *
 *  Created on: Jun 4, 2022
 *      Author: soft
 */

#include<stdio.h>

int main()
{
	//search in array
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
		printf("\nEnter element:");
			fflush(stdout);
			scanf("%d",&elem);
			for(i=0;i<num;i++){
				if(arr[i]==elem){
					loc=i;
				}
			}
			printf("number found in loction=%d",loc+1);
}
