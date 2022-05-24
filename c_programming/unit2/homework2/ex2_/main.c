/*
 * main.c
 *
 *  Created on: May 24, 2022
 *      Author: soft
 */

#include <stdio.h>

int main(){
	// program to check alphabet vowel or consonant
	char alpha;
	printf("Enter an Alphabet:");
	fflush(stdout);
	scanf("%c",&alpha);
	if(alpha=='a'||alpha=='e'||alpha=='o'||alpha=='i'||alpha=='u'||alpha=='A'||alpha=='E'||alpha=='O'||alpha=='I'||alpha=='U'){
		printf("%c is vowel",alpha);
	}
	else
		printf("%c is consonant",alpha);






}
