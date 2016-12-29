#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define max_length 35
#define group_name_length 5

typedef struct Group {
	int course;
	char group_name[group_name_length];
} group;

typedef struct Gradebook {
	int score;
	_Bool is_accepted; // true if Gradebook is signed by teacher
} gradebook;

typedef struct WorkFile {
	char work_box[CHAR_MAX];
	char comment_box[CHAR_MAX];
} work_file;

typedef struct Student {
	char first_name[max_length];
	char last_name[max_length];
	int age;
	_Bool access;
	gradebook *gradebook_data;
	group *group_data;
	work_file *work_data;
} student;

typedef struct Auth {
	char login[max_length];
	char password[max_length];
} auth;

typedef struct Lecturer {
	char first_name[max_length];
	char last_name[max_length];
	char subject[max_length];
	auth *auth_data;
} lecturer;

void create_student(student *student_b);
char *get_student_name(void);
void create_group(group *group_b);
char *get_group_name(void);
void create_lecturer(lecturer *lecturer_b);
void create_auth(auth *auth_b);
char *get_auth();

int main() {
	student *student_b = NULL;
	group *group_b = NULL;
	lecturer *lecturer_b = NULL;
	auth *auth_b = NULL;

	student_b = (student *)malloc(sizeof(student));
	group_b = (group *)malloc(sizeof(group));
	lecturer_b = (lecturer *)malloc(sizeof(lecturer));
	auth_b = (auth *)malloc(sizeof(auth));

	student_b->group_data = group_b;
	lecturer_b->auth_data = auth_b;

	create_student(student_b);
	create_group(group_b);
	create_lecturer(lecturer_b);
	create_auth(auth_b);

	system("cls");
	getchar();
	return 0;
}
void create_student(student *student_b) {
	char *buffp;
    strcpy(student_b->first_name,"\0");
    strcpy(student_b->last_name,"\0");
    while(!strcmp(student_b->first_name,"\0")) {
    printf("\nEnter the first student name: ");
    buffp = get_student_name();
    strcpy(student_b->first_name, buffp);

    system("cls");
    }
    while(!strcmp(student_b->last_name,"\0")) {
    printf("\nEnter the last student name: ");
    buffp = get_student_name();
    strcpy(student_b->last_name, buffp);

    system("cls");
	}
}

char *get_student_name(void) {
	char buf[max_length*2];
	char *buffp;
	int i=0, j;
	fflush(stdin);
	gets(buf);
	buffp = (char *)malloc(strlen(buf)*sizeof(char));
	if ((strlen(buf) > max_length) || (strlen(buf) == 0))
            i=1;

    for (j=0; j < strlen(buf); j++)
    	if(!(isalpha(buf[j])))
        	i=1;
   if(i==1)
    {
        printf("\nInvalid input! Press any key to write a name: ");
        getchar();
        strcpy(buffp, "\0");
        return buffp;
    }
    else
    return  strcpy(buffp, buf);
}

char *get_group_name(void) {
	char *buffp;
  	char buf[group_name_length*2];
  	int i=0,j;
	gets(buf);
   	buffp=(char *)malloc(strlen(buf)*sizeof(char));
    if ((strlen(buf)>group_name_length)||(strlen(buf)==0))
        i=1;

    for(j=0; j<strlen(buf); j++) {
        if(!isalpha(buf[j]))
            i=1;
        if(buf[j]=="-")
            i=0;
    }
   if(i==1) {
    	printf("\nInvalid input");
        getchar();
        strcpy(buffp,"\0");
        return buffp;
    }
    else
    	return  strcpy(buffp, buf);
}

void create_group(group *group_b) {
	char *buffp;
    group_b->course = -1;
    strcpy(group_b->group_name,"\0");

    while(!strcmp(group_b->group_name,"\0")) {
    	printf("\nEnter group name: ");
    	buffp = get_group_name();
    	strcpy(group_b->group_name, buffp);

    	system("cls");
    }

    while(group_b->course == -1) {
    	printf("\nEnter course: ");
    	group_b->course=get_student_course();

    	system("cls");
    }
}

void create_lecturer(lecturer *lecturer_b) {
	printf(" ");
}
void create_auth(auth *auth_b) {
	printf(" ");
}

