/*
 * main.c
 *
 *  Created on: Jun 4, 2022
 *      Author: soft
 */

#include<stdio.h>

int main()
{
	//program to take a string and count repeated specific character
	char string[100];
	char c,sum=0,i,count=0;
	printf("Enter an string:");
	fflush(stdout);
	gets(string);
	printf("Enter character:");
	fflush(stdout);
	scanf("%c",&c);
	for(i=0;i<100;i++){
		if(string[i]==c){
			count++;
		}
	}
	printf("Repeated %d times",count);
}
