/*
 * main.c
 *
 *  Created on: Jun 5, 2022
 *      Author: soft
 */

#include<stdio.h>
//#include <string.h>
int main()
{
	// program to calculate string length
	char a[100],i=0,count=0;
	printf("Enter a string:");
	fflush(stdout);
	gets(a);
	printf("you entered :%s\n",a);
	// strlen
	//int b=strlen(a);
	//printf("%d",b);
	while(a[i]!='\0'){
		count++;
		i++;

	}
	printf("length of string= %d",count);
}
