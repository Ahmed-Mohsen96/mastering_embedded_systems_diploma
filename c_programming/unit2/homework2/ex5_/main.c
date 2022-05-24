/*
 * main.c
 *
 *  Created on: May 24, 2022
 *      Author: soft
 */

// program to check alphabet or not

#include<stdio.h>

int main(){
	char a;
	printf("Enter a character");
	fflush(stdout);
	scanf("%c",&a);
	if(a>='a'&&a<='z'||a>='A'&&a<='Z'){
		printf("%c is alphabet");
	}
	else
		printf("%c is not alphabet");
}
