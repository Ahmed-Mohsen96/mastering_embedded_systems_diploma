/*
 * main.c
 *
 *  Created on: Sep 18, 2022
 *      Author: soft
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include"fifo.h"





int main()
{

	element_type i,temp_text[50];
	if(fifo_init()==fifo_no_error)
		Dprintf("======fifo init done =============\n");
	while(1){
		Dprintf("choose the task:\n");
		Dprintf("1-add student from file :\n");
		Dprintf("2-add student manually :\n");
		Dprintf("3-delete student:\n");
		Dprintf("4-print student:\n");
		Dprintf("5-print student by roll id:\n");
		Dprintf("6-print student by first name:\n");
		Dprintf("7-print number of student:\n");
		Dprintf("8-update student:\n");

		gets(temp_text);
		switch(atoi(temp_text)){
		case 1:
			Add_student_from_file();
			break;
		case 2:
			add_student();
			break;
		case 3:
			delete_student();
			break;
		case 4:
			print_all_student();
			break;
		case 5:
			find_student_id();
			break;
		case 6:
			find_student_first();
			break;
		case 7:
			count_student();
			break;
		case 8:
			update_students();
			break;

		}
	}




	return 0;
}

