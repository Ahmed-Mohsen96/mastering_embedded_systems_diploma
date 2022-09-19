/*
 * fifo.h
 *
 *  Created on: Sep 18, 2022
 *      Author: soft
 */

#ifndef FIFO_H_
#define FIFO_H_

#include<stdio.h>
#include "stdint.h"
#include <string.h>
#include <stdlib.h>

#define Dprintf(...)			{fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}
//user configration

// select element type (uint8,uint16,.....)
#define element_type Sinfo_t
//create a static buffer
#define length1 50
//element_type buffer[length1];
//students elements

//fifo data types
typedef struct {
		char fname[50];
		char lname[50];
		unsigned int roll;
		float GPA;
		unsigned int courses_id[10];
	}Sinfo_t;
typedef struct{

	unsigned int count;
	unsigned int length;
	element_type* base;
	element_type* head;
	element_type* tail;

}fifo_buf_t;
typedef enum{
	fifo_no_error,
	fifo_null,
	fifo_empty,
	fifo_full,
	error
}num_status_buf_t;

// fifo APIS
num_status_buf_t fifo_init();
num_status_buf_t add_student();
num_status_buf_t delete_student();
num_status_buf_t print_all_student();
num_status_buf_t fifo_buf_is_full();
num_status_buf_t find_student_id();
num_status_buf_t find_student_first();
num_status_buf_t count_student();
num_status_buf_t update_students();
num_status_buf_t Add_student_from_file ();




#endif /* FIFO_H_ */
