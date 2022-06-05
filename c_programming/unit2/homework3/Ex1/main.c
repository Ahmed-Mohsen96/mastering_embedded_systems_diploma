/*
 * main.c
 *
 *  Created on: Jun 3, 2022
 *      Author: soft
 */

#include <stdio.h>

int main()
{
	// calculate sum of 2 matrix 2*2
	float a[2][2];
	float b[2][2];
	int i,j;
	printf("the first matrix\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Enter a(%d,%d):",i,j);
			fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}
	printf("the second matrix\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Enter b(%d,%d):",i,j);
			fflush(stdout);
			scanf("%f",&b[i][j]);
		}
	}
	// sum of matrixes
	float sum[2][2]={0};
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			sum[i][j]+=(a[i][j]+b[i][j]);
		}
	}
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%.2f\t",sum[i][j]);

		}
		printf("\n");
	}

}
