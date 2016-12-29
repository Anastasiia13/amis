#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "stack.h"
#include "validation.h"

enum Faculties {
	FAM, FICT
};

struct Student{
	char Name[20];
	char Surname[20];
	char Group[5];
	float Scholarship;
};

struct Teacher{
	char Name[20];
	char Surname[20];
	enum Faculties faculty;
	char Subject[20];
};

struct Comission{
	struct Teacher teachers[5];
};


int main(){
	struct Student * student_1 = malloc(sizeof(struct Student));
	
	printf("Enter student's name: ");
	get_string(&(student_1->Name[0]), 22, 0, 20);
	
	printf("\nEnter srudent's surname: ");
	get_string(&(student_1->Surname[0]), 25, 1, 20);
	
	printf("\nEnter student's scholarship(UAH): ");
	student_1->Scholarship = get_float(34, 2, 4);
	
	printf("\nEnter student's group: ");
	get_group(&(student_1->Group[0]), 23, 3);
	
	return 0;
}
