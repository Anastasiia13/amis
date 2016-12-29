#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  struct student{
	char first_name[10];
	char last_name[10];
	int course_number;
	char group[10];
}; 

typedef struct work_book{
	enum subject{
		 math,
		 physics,
		 english, 
		 ukrainian
		 };
	enum language{
	     Ukrainian,
	     Russian,
	     English
		 };
	struct student *Student;
}work_book;

typedef struct formating{
	int text_size;
	enum text_color{
		black,
		red,   // for main information
		green  
		};
}formating;

int main ()
 {
 struct formating *new_formating = NULL;
 struct work_book *new_work_book = NULL;
 new_formating=(struct formating *)malloc(sizeof( struct formating));
 new_work_book=(struct work_book *)malloc(sizeof( struct work_book));
 
 free(new_formating);
 free(new_work_book);
 return 0;
 }

