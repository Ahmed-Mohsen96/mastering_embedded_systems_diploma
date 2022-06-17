/*
 * main.c
 *
 *  Created on: Jun 16, 2022
 *      Author: soft
 */

#include<stdio.h>

//reverse sentence using recursion

void reverse(){
	char c;
	fflush(stdout);
	scanf("%c",&c);
	if(c != '\n'){
		reverse();
		printf("%c",c);
	}

}
int main(){

	printf("Enter a sentence:");
	reverse();





	return 0;


}
