/*
 * main.c
 *
 *  Created on: Aug 20, 2022
 *      Author: soft
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>


#define Dprintf(...)			{fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}
//user data
struct sdata{
	unsigned char name[40];
	unsigned int id;
	float height;
};

// node data
struct SStudent{
	struct sdata student;
	struct SStudent* pnextstudent;
};
struct SStudent* gpfirst='\0';
// adding data
struct SStudent add_student()
{
	struct SStudent* pnewstudent;
	struct SStudent* plaststudent;
	unsigned char temp_text[40];
	//check empty yes
	if(gpfirst=='\0'){
		//assign nwe record
		pnewstudent=(struct SStudent*)malloc(sizeof(struct SStudent));
		//set new student to gpfirst
		gpfirst=pnewstudent;
	}
	// no
	else{
		plaststudent=gpfirst;
		while(plaststudent->pnextstudent){
			plaststudent=plaststudent->pnextstudent;
		}

		//new record
		pnewstudent=(struct SStudent*)malloc(sizeof(struct SStudent));
		//set plast st to new
		plaststudent->pnextstudent=pnewstudent;


	}
	//adding student data
	Dprintf("\n Enter student id:");
	gets(temp_text);
	pnewstudent->student.id=atoi(temp_text);

	Dprintf("\n Enter student full name:");
	gets(pnewstudent->student.name);


	Dprintf("\n Enter student height:");
	gets(temp_text);
	pnewstudent->student.height=atof(temp_text);
	//set nextstudent to null
	pnewstudent->pnextstudent='\0';
}
// delete specific id
int delete_student()
{
	unsigned char temp_text[20];
	unsigned int  selected_id;
	// read id
	Dprintf("\nEnter id number:");
	gets(temp_text);
	selected_id=atoi(temp_text);
	if(gpfirst){
		struct SStudent* PselectdStudent=gpfirst;
		struct SStudent* PpreviousStudent='\0';
		//loop in all record
		while(PselectdStudent)
		{
			// compare each id with slected id
			if(PselectdStudent->student.id==selected_id)
			{
				if(PpreviousStudent)// first is selected not
				{

					PpreviousStudent->pnextstudent=PselectdStudent->pnextstudent;
				}
				else // selected is == id
				{
					gpfirst=PselectdStudent->pnextstudent;

				}
				free(PselectdStudent);
				return 1;
			}
			PpreviousStudent=PselectdStudent;
			PselectdStudent=PselectdStudent->pnextstudent;
		}

		return 0;
	}
}

//print student
void print_student()
{
	struct SStudent* pcurentstudent;
	//check empty
	if(gpfirst=='\0')
	{Dprintf("Empty");}
	else
	{
		pcurentstudent=gpfirst;
		unsigned int count=0;
		while(pcurentstudent)
		{
			Dprintf("\n RECORD student %d",count+1);
			Dprintf("\n student id %d",pcurentstudent->student.id);
			Dprintf("\n student full name  %s",pcurentstudent->student.name);
			Dprintf("\n student id %f",pcurentstudent->student.height);
			Dprintf("\n===============\n");
			count ++;
			pcurentstudent=pcurentstudent->pnextstudent;

		}
	}
}
// delete all
void delete_all()
{
	struct SStudent* pcurentstudent;
	//check empty
	if(gpfirst=='\0')
	{Dprintf("Empty");}
	else
	{
		pcurentstudent=gpfirst;

		while(pcurentstudent)
		{
			struct SStudent* ptempstudent=pcurentstudent;
			pcurentstudent=pcurentstudent->pnextstudent;
			free(ptempstudent);


		}
		gpfirst='\0';
	}
}
//function to get Nth node
int get_Nth_node(int index)
{
	unsigned int count=0;

	struct SStudent* pcurrent_index=gpfirst;
	//loop while list
	while(pcurrent_index!='\0')
	{
		if(count==index){
			Dprintf("the node at index %d is %d\n",count,pcurrent_index->student.id);
			return 0;
		}
		else{
			pcurrent_index=pcurrent_index->pnextstudent;
			count ++;
			continue;

		}

	}
	Dprintf("\n index is not Exist\n");
	return 0;
}
// Nth node from the end
int get_Nth_node_end(int index){
	unsigned int length=count_elements();
	unsigned int len=(length-index);
	unsigned int count=0;
	struct SStudent* pcurrent_index=gpfirst;
	//loop while list
	while(pcurrent_index!='\0')
	{
		if(count==len){
			Dprintf("the node at index %d is %d\n",count,pcurrent_index->student.id);
			return 0;
		}
		else{
			pcurrent_index=pcurrent_index->pnextstudent;
			count ++;
			continue;
		}

	}
	Dprintf("\n index is not Exist\n");
	return 0;
}
//count elements in linked list
int count_elements()
{

	//check is empty
	if(gpfirst=='\0')
		Dprintf("empty");
	unsigned char count=0;
	struct SStudent* pcurrentelement=gpfirst;
	while(pcurrentelement)
	{
		pcurrentelement=pcurrentelement->pnextstudent;
		count++;

	}
	//Dprintf("\n number of student is :%d",count);
	return count;
}
//find the middle of linked list
int mid_student()
{
	unsigned int length=count_elements();
	//if length is odd
	if(length==1||length==2){
		Dprintf("no middle student");
		return 0;}
	else if(length%2!=0)
	{
		length=(length/2);
		get_Nth_node(length);
	}
	// if length is even
	else
	{
		Dprintf("\nlinked list is even\n");
		length=(length/2);
		get_Nth_node(length-1);
		get_Nth_node(length);
	}
}
//reverse students
int reverse_student()
{
	struct SStudent* pcurrentStudent=gpfirst;
	struct SStudent* pnext=gpfirst;
	struct SStudent* pprevious='\0';
	while(pcurrentStudent){
		pnext=pcurrentStudent->pnextstudent;
		pcurrentStudent->pnextstudent=pprevious;
		pprevious=pcurrentStudent;
		pcurrentStudent=pnext;

	}
	gpfirst=pprevious;
	Dprintf("reverse is done\n");

}
int main()
{
	unsigned char temp_text[40],count;
	while(1)
	{
		Dprintf("\n ======================");
		Dprintf("\n Enter option :");
		Dprintf("\n 1- add student");
		Dprintf("\n 2- print student");
		Dprintf("\n 3- delete student");
		Dprintf("\n 4- delete all student");
		Dprintf("\n 5- number of students");
		Dprintf("\n 6- gets Nth node");
		Dprintf("\n 7- gets Nth node from end ");
		Dprintf("\n 8- gets middle student ");
		Dprintf("\n 9- reverse student ");
		Dprintf("\n ======================\n");
		gets(temp_text);
		switch(atoi(temp_text)){
		case 1:
			add_student();
			break;
		case 2:
			print_student();
			break;
		case 3:
			delete_student();
			break;
		case 4:
			delete_all();
			break;
		case 5:
			count=count_elements();
			Dprintf("\n number of student =%d\n",count);
			break;
		case 6:
			Dprintf("\nEnter index:")
			gets(temp_text);
			get_Nth_node(atoi(temp_text));
			break;
		case 7:
			Dprintf("\nEnter index:")
			gets(temp_text);
			get_Nth_node_end(atoi(temp_text));
			break;
		case 8:
			mid_student();
			break;
		case 9:
			reverse_student();
			break;
		default:
			Dprintf("no option");

		}
	}
	return 0;
}
