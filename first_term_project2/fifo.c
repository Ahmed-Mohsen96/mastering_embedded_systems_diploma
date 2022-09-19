/*
 * fifo.c
 *
 *  Created on: Sep 18, 2022
 *      Author: soft
 */
#include"fifo.h"
element_type arr[length1];
fifo_buf_t ptr;
num_status_buf_t fifo_init(){
	//check fifo null

	ptr.base=arr;
	ptr.head=arr;
	ptr.tail=arr;
	ptr.length=length1;
	ptr.count=0;

	return fifo_no_error;
}
num_status_buf_t Add_student_from_file ()
{

	//check list initialized

	if(!ptr.base ||!ptr.head)
		return fifo_null ;

	//check list full or not


	if(ptr.count==ptr.length)
	{
		Dprintf("\n Error it is full");
		return fifo_full;
	}
	int i ;
	FILE *pfile;
	pfile=fopen("ahmed.txt","r");
	// lobe until reach to last line
	while (!feof(pfile))
	{
		fscanf(pfile,"%d",&ptr.head->roll);


		//store data
		fscanf(pfile,"%s",ptr.head->fname);
		fscanf(pfile,"%s",ptr.head->lname);
		fscanf(pfile,"%f",&ptr.head->GPA);
		for (i=0;i<5;i++)
		{
			fscanf(pfile,"%d",&ptr.head->courses_id[i]);
		}

		ptr.head++;
		ptr.count++;

	}
	fclose(pfile);
	Dprintf("\n You Can Enter Another (%d) student ",50-ptr.count);
	Dprintf("\n _______________________________________________________");
	return fifo_no_error ;
}
num_status_buf_t add_student(){
	unsigned char temp[40];
	int i;
	if(!ptr.tail ||!ptr.head ||!ptr.base )
		return fifo_null;
	//check full
	if(ptr.count==ptr.length){
		Dprintf("\n Error it is full");
		return fifo_full;
	}
	//add data
	Dprintf("Enter student number %d data \n",ptr.count+1);
	Dprintf("Enter roll number\n ");
	gets(temp);
	//check roll exist before
	//if(temp_text==)
	ptr.head->roll=atoi(temp);
	//check roll number founded or not
	element_type* selected_roll=ptr.base;
	while(selected_roll !=ptr.head)
	{
		if(selected_roll->roll ==ptr.head->roll)
		{
			Dprintf("\n Error This Roll Number Is Founded,it is information for that student");
			//printstudent(selected_roll);
			return error; ;
		}
		selected_roll++ ;

	}
	Dprintf("\nEnter first name  ");
	gets(ptr.head->fname);

	Dprintf("\nEnter last name  ");
	gets(ptr.head->lname);

	Dprintf("\nEnter GPA  ");
	//gets(temp_text);

	scanf("%f",&ptr.head->GPA);
	//ptr.head->GPA=atof(temp_text);

	Dprintf("\nEnter course code  ");
	for(i=0;i<10;i++){
		Dprintf("\n Enter course ID (%d) : ",i+1);
		gets(temp);
		ptr.head->courses_id[i]=atoi(temp);
	}


	ptr.count++;
	if(ptr.count==ptr.length)
	{
		ptr.head=ptr.base;
	}
	ptr.head++;
	Dprintf("\n You Can Enter Another (%d) student ",50-ptr.count);
	Dprintf("\n _______________________________________________________");
	return fifo_no_error;
}
num_status_buf_t delete_student(){
	if(!ptr.base||!ptr.head||!ptr.tail)
		return fifo_null;
	if(ptr.count==0){
		Dprintf("\n You Can Not Delete Any Student list Is Empty");
		return fifo_empty;
	}

	int roll_del;
	Dprintf("\nEnter roll number you need to delete\n");
	scanf("%d",&roll_del);
	int i;
	for(i=0;i<ptr.count;i++)
	{
		if(roll_del==(ptr.tail+i)->roll){
			ptr.count--;
			if(ptr.tail==ptr.length)
			{
				ptr.tail=ptr.base;
			}
			ptr.tail++;

		}
	}
	Dprintf("\n You Can Enter Another (%d) student ",50-ptr.count);


}
num_status_buf_t print_all_student(){
	element_type* temp;
	int i,j;
	if(ptr.count==0)
		return fifo_empty;
	temp=ptr.tail;
	printf("\n========fifo print=========\n");
	for(i=0;i<ptr.count;i++)
	{
		Dprintf("\n student number %d data\n ",i+1);

		Dprintf("\t %d \n",temp->roll);
		Dprintf("\t %s \n",temp->fname);
		Dprintf("\t %s \n",temp->lname);
		Dprintf("\t %f \n",temp->GPA);
		for(j=0;j<10;j++){
			Dprintf("\t %d \n",temp->courses_id[j]);}

		temp++;
	}
	printf("\n==================\n");

}

num_status_buf_t find_student_id(){
	int i,j,id;
	element_type* temp;
	if(ptr.count==0)
		return fifo_empty;
	// enter id to compare
	Dprintf("Enter student id :\n");
	scanf("%d",&id);
	//check id
	temp=ptr.tail;
	while(temp !=ptr.head)
	{
		if(id==temp->roll)
		{
			Dprintf("\t %d \n",temp->roll);
			Dprintf("\t %s \n",temp->fname);
			Dprintf("\t %s \n",temp->lname);
			Dprintf("\t %f \n",temp->GPA);
			for(j=0;j<10;j++){
				Dprintf("\t %d \n",temp->courses_id[j]);}
		}
		temp++;

	}


}
num_status_buf_t find_student_first(){
	int i,j;
	char fname[50];
	element_type* temp;
	if(ptr.count==0)
		return fifo_empty;
	// enter id to compare
	Dprintf("\n Enter student first name :\n");
	gets(fname);
	//check id
	temp=ptr.base;
	while(temp != ptr.head)
	{
		if(strcmp(fname,temp->fname)==0)
		{
			Dprintf("\t %d \n",temp->roll);
			Dprintf("\t %s \n",temp->fname);
			Dprintf("\t %s \n",temp->lname);
			Dprintf("\t %f \n",temp->GPA);
			for(j=0;j<10;j++){
				Dprintf("\t %d \n",temp->courses_id[j]);}		}
		temp++;

	}

	Dprintf("\n name not founded :\n");

}
num_status_buf_t count_student(){
	if(ptr.count==0)
		return fifo_empty;
	Dprintf("\n%d\n",ptr.count);

}
num_status_buf_t update_students(){

	//check list initialized
		if(!ptr.base ||!ptr.head)
			return fifo_null ;

		int new_roll ;
		element_type* find_roll =ptr.base ;
		int selected_roll ;
		char temp[10];
		Dprintf("\n Enter roll number of student to update information  : ");
		gets(temp);
		selected_roll =atoi(temp) ;
		int x=0;
		while(find_roll !=ptr.head)
		{
			int i ;
			char var[10];
			if(selected_roll==find_roll->roll)
			{
				x=1 ;
				Dprintf(" \n chose the task that you want to update it :");
				Dprintf("\n 1:first name");
				Dprintf("\n 2:second name ");
				Dprintf("\n 3:roll number ");
				Dprintf("\n 4:GPA ");
				Dprintf("\n 5:courses ");
				Dprintf(" \n Enter Your Choice: ");
				gets(temp);
				switch (atoi(temp))
				{
				case 1:
					Dprintf("\n Enter new first name: ");
					gets(find_roll->fname);
					break;
				case 2:
					Dprintf("\n Enter new second name: ");
					gets(find_roll->lname);
					break ;
				case 3:

					Dprintf("\n Enter new roll number: ");
					gets(temp);
					new_roll= atoi(temp);
	// check if new roll number is founded or not

					find_roll->roll=new_roll;

					break;
				case 4:
					Dprintf("\n Enter new GPA: ");
					gets(var);
					find_roll->GPA = atoi(var);
					break ;
				case 5:
					Dprintf("\n Enter new courses: ");
					for (i=0;i<5;i++)
					{
						Dprintf("\n Enter course %d : ",i+1);
						gets(var);
						find_roll->courses_id[i] = atoi(var);
					}
					break ;
				default :
					break;

				}

			}

			find_roll++;

		}
	// check if entered roll number of student to be update is found or not
		if(x==0)
		{
			Dprintf("\n This Roll Number Is Not Founded");
			Dprintf("\n ===================================");

			return error ;
		}
		else
		{

			return fifo_no_error;
		}

	}


