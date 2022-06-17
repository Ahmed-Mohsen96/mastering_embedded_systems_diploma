/*
 * main.c
 *
 *  Created on: Jun 17, 2022
 *      Author: soft
 */


#include <stdio.h>
// calculate power of number using recursion

int power_(int base,int pow_num){
	 if(pow_num!=0){
		 return (base*power_(base,pow_num-1));
	 }
	 else
		 return 1;
}
int main()
{
	int base,pow_num;
	printf("Enter base number:");
	fflush(stdout);
	scanf("%d",&base);
	printf("Enter power number(positive):");
	fflush(stdout);
	scanf("%d",&pow_num);

	/*for(i=0;i<pow_num;i++){
		mulit *= power_(base);
	}*/

	printf("%d ^ %d = %d ",base,pow_num,power_(base,pow_num));




	return 0;
}
