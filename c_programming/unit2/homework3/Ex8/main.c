/*
 * main.c
 *
 *  Created on: Jun 5, 2022
 *      Author: soft
 */


#include<stdio.h>
#include<string.h>


int main()
{
	// program to reverse string
	char s[100],r[100],i,j;
	printf("Enter a string:");
	fflush(stdout);
	gets(s);
	int size=strlen(s);
	//reversing
	for(i=0,j=size-1;i<size;i++,j--){
		r[i]=s[j];
	}
	r[i]='\0';
	printf("%s",r);
}
