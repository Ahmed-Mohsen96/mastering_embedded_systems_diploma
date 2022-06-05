/*
 * main.c
 *
 *  Created on: Jun 3, 2022
 *      Author: soft
 */
#include <stdio.h>


int main()
{
	//program to find transpose of matrix
	int r,c,i,j;
	int m[10][10],tr[10][10];
	printf("Enter rows and colums:");
	fflush(stdout);
	scanf("%d %d",&r,&c);
	// matrix

	printf("\nEnter elements of matrix:\n");
	for(i=0;i<r;++i){
		for(j=0;j<c;++j){
			printf("enter elements of a %d,%d:\n",i+1,j+1);
			fflush(stdout);
			scanf("%d",&m[i][j]);
		}
	}
	printf("The matrix:\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
	printf("transpose of matrix:\n");

	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			tr[j][i]=m[i][j];
		}
	}
	for(i=0;i<c;i++){
			for(j=0;j<r;j++){
				printf("%d\t",tr[i][j]);
			}
			printf("\n");
		}
}

