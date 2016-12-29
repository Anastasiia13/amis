#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

COORD coord={0,0};
void gotoxy(int x,int y) {
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void SetColor(int text, int background)
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

int s = 0, t = 0, tc = 0, m = 0;
char Key1;

typedef struct student_info {
	char name[30];
  	char surname[50];
   	char group[10];
   	struct student_info *next;
} students;
students *head_s, *next_s, *del_s;

typedef struct theme {
	char theme_name[50];
  	bool origin;
   	struct theme *next1;
} themes;
themes *head_t, *next_t, *del_t;
    
typedef struct teacher_info {
	char name[30];
   	char surname[50];
   	struct teacher_info *next2;
} teachers;
teachers *head_tc, *next_tc, *del_tc;
    
typedef struct mark {
	struct student_info;
   	int student_mark;
   	struct mark *next3;
} marks;
marks *head_m, *next_m, *del_m;
    
char get_student_name() {
	printf("Enter student`s firstname: ");
	gets(next_s->name);
    while(strlen(next_s->name) < 2 || strlen(next_s->name) > 30){
    	gotoxy(0, 0);
		SetColor(4, 0);
		printf("Enter student`s firstname: ");
		SetColor(7, 0);
		gets(next_s->name);
	}
	gotoxy(0, 0);
	SetColor(7, 0);
	gotoxy(0, 1);
	return next_s->name;
}

char get_student_surname() {
	printf("Enter student`s surname: ");
    gets(next_s->surname);
    while(strlen(next_s->surname) < 2 || strlen(next_s->surname) > 30){
       	gotoxy(0, 1);
		SetColor(4, 0);
		printf("Enter student`s surname: ");
		SetColor(7, 0);
		gets(next_s->surname);
	}
	gotoxy(0, 1);
	SetColor(7, 0);
	gotoxy(0, 2);
	return next_s->surname;
}

char get_student_group() {
	printf("Enter group: ");
    gets(next_s->group);
    while(strlen(next_s->group) < 2 || strlen(next_s->group) > 30){
       	gotoxy(0, 2);
		SetColor(4, 0);
		printf("Enter group: ");
		SetColor(7, 0);
		gets(next_s->group);
	}
	next_s->next = head_s;
	head_s = next_s;
	return next_s->group;
}

students * create_student() {
	system("cls");
	next_s = malloc(sizeof(students));
	get_student_name();
	get_student_surname();
	get_student_group();
	s++;
	return next_s;
}

char get_theme_name() {
	printf("Enter theme name: ");
    gets(next_t->theme_name);
    while(strlen(next_t->theme_name) > 50) {
      	gotoxy(0, 0);
		SetColor(4, 0);
		printf("Enter theme name: ");
		SetColor(7, 0);
   		gets(next_t->theme_name);
	}
	gotoxy(0, 0);
	SetColor(7, 0);
	gotoxy(0, 2);
	return next_t->theme_name;
}

bool get_theme_origin() {
	printf("Is these theme default?\n");
	printf("'Enter' - yes\n");
	printf("'Esc' - no");
	Key1 = getch();
	while (Key1 != 13 && Key1 != 27) {
		gotoxy(0, 2);
		SetColor(4, 0);
		printf("Is these theme default?\n");
		printf("'Enter' - yes\n");
		printf("'Esc' - no");
		SetColor(7, 0);
		Key1 = getch();
	}
	if (Key1 == 13)
		next_t->origin = true;
	else if (Key1 == 27)
		next_t->origin = false;
	next_t->next1 = head_t;
	head_t = next_t;
	return next_t->origin;
}

themes * create_theme() {
	system("cls");
	next_t = malloc(sizeof(themes));
	get_theme_name();
	get_theme_origin();
	t++;
	return next_t;
}

char get_teacher_name() {
	printf("Enter teacher`s firstname: ");
	gets(next_tc->name);
	while(strlen(next_tc->name) < 2 || strlen(next_tc->name) > 30) {
		gotoxy(0, 0);
		SetColor(4, 0);
		printf("Enter teacher`s firstname: ");
		SetColor(7, 0);
		gets(next_tc->name);
	}
	gotoxy(0, 0);
	SetColor(7, 0);
	gotoxy(0, 1);
	return next_tc->name;
}

char get_teacher_surname() {
	printf("Enter teacher`s surname: ");
	gets(next_tc->surname);
	while(strlen(next_tc->surname) < 2 || strlen(next_tc->surname) > 30){
	   	gotoxy(0, 1);
		SetColor(4, 0);
		printf("Enter teacher`s surname: ");
		SetColor(7, 0);
		gets(next_tc->surname);
	}
	gotoxy(0, 1);
	SetColor(7, 0);
	next_tc->next2 = head_tc;
	head_tc = next_tc;
	return next_tc->surname;
}

teachers * create_teacher() {
	system("cls");
	next_tc = malloc(sizeof(teachers));
	get_teacher_name();
	get_teacher_surname();
	tc++;
	return next_tc;
}

int get_student_mark() {
	printf("Enter mark of student ¹%d: ", m+1);
	while(scanf("%d", &next_m->student_mark)!=1 || next_m->student_mark < 0 || next_m->student_mark > 100){
	   	gotoxy(0, 0);
		SetColor(4, 0);
		printf("Enter mark of student ¹%d: ", m+1);
		SetColor(7, 0);
		fflush(stdin);
	}
	gotoxy(0, 0);
	SetColor(7, 0);
	next_m->next3 = head_m;
	head_m = next_m;
	return next_m->student_mark;
}

marks * create_mark() {
	system("cls");
	next_m = malloc(sizeof(marks));
	if (s != 0) {
		get_student_mark();
		m++;
	}
	else {
		printf("Please, add a student!");
		getch();
	}
	return next_m;
}

int main (void) {
	char Key;
	head_s = NULL;
	head_t = NULL;
	head_tc = NULL;
	head_m = NULL;
	while (1) {
		setlocale(LC_ALL, "rus");
		system("cls");
		printf("________________________________________________________________________________");
		printf("|                         Author: Selskiy E., Group: KM-52                     |");
		printf("|______________________________________________________________________________|");
	    gotoxy(25, 8);
	    printf("'1' - Add student");
	    gotoxy(25, 9);
	    printf("'2' - Add theme");
	    gotoxy(25, 10);
	    printf("'3' - Add teacher");
	    gotoxy(25, 11);
	    printf("'4' - Add mark");
	    gotoxy(25, 12);
	    printf("'5' - Show all records");
	    gotoxy(34, 13);
	    printf("'Esc' - Exit");
	    Key = getch();   
		while (Key != '1' && Key != '2' && Key != '3' && Key != '4' && Key != '5' && Key != 27) {
	        system("cls");
	        printf("________________________________________________________________________________");
		    printf("|                         Author: Selskiy E., Group: KM-52                     |");
		    printf("|______________________________________________________________________________|");
		    SetColor(4, 0);
		    gotoxy(25, 8);
		    printf("'1' - Add student");
		    gotoxy(25, 9);
		    printf("'2' - Add theme");
		    gotoxy(25, 10);
		    printf("'3' - Add teacher");
		    gotoxy(25, 11);
		    printf("'4' - Add mark");
		    gotoxy(25, 12);
		    printf("'5' - Show all records");
		    gotoxy(34, 13);
		    printf("'Esc' - Exit");
		    SetColor(7, 0);
	    	Key = getch();
		}
		if (Key == '1') {
			create_student();
		}
		else if (Key == '2') {
			create_theme();
		}
		else if (Key == '3') {
			create_teacher();
		}
		else if (Key == '4') {
			create_mark();
		}
		else if (Key == '5') {
			next_s = head_s;
			next_t = head_t;
			next_tc = head_tc;
			next_m = head_m;
			system("cls");
			int i = s;
			printf("Students:\n");
			while(next_s != NULL) {
				printf("%d: \n", i);
				printf("Name: ");
				puts(next_s->name);
				printf("Surname: ");
				puts(next_s->surname);
				printf("Group: ");
				puts(next_s->group);
				printf("\n");
				next_s = next_s->next;
				i--;
			};
			printf("\n");
			i = t;
	        printf("Themes:\n");
	        while(next_t != NULL) {
	        	printf("%d: \n", i);
	        	printf("Theme name: ");
				puts(next_t->theme_name);
				printf("Origin: ");
				if (next_t->origin)
					printf("Default theme \n");
				else
					printf("Student`s theme \n");	
				printf("\n");
				next_t = next_t->next1;
				i--;
			};
			printf("\n");
			i = tc;
			printf("Teachers:\n");
	        while(next_tc != NULL) {
	        	printf("%d: \n", i);
	        	printf("Name: ");
				puts(next_tc->name);
				printf("Surname: ");
				puts(next_tc->surname);
				printf("\n");
				next_tc = next_tc->next2;
				i--;
			};
			printf("\n");
			next_s = head_s;
			i = min(s, m);
			printf("Marks:\n");
	        while(next_m != NULL && next_s != NULL) {
	        	printf("%d: \n", i);
				printf("Name: ");
				puts(next_s->name);
				printf("Surname: ");
				puts(next_s->surname);
				printf("Group: ");
				puts(next_s->group);
				printf("Mark: ");
				printf("%d", next_m->student_mark);
				printf("\n");
				next_s = next_s->next;
				next_m = next_m->next3;
				i--;
			};
			printf("\t\t\tAny button - back to menu");
	        getch();
		}
		else if (Key == 27) {
			if (s == 0 || m == 0 || t == 0 || tc ==0)
				break;
			else {	
				del_s = head_s;
				del_t = head_t;
				del_tc = head_tc;
				del_m = head_m;
				next_s->next = del_s; 
				next_t->next1 = del_t; 
				next_tc->next2 = del_tc; 
				next_m->next3 = del_m; 
				while(s > 0) {
					free(del_s);
					del_s = next_s;
					next_s->next = del_s;
					s--;
				}
				while(t > 0) {
					free(del_t);
					del_t = next_t;
					next_t->next1 = del_t;
					t--;
				}
				while(tc > 0) {
					free(del_tc);
					del_tc = next_tc;
					next_tc->next2 = del_tc;
					tc--;
				}
				while(m > 0) {
					free(del_m);
					del_m = next_m;
					next_m->next3 = del_m;
					m--;
				}
				break;
			}
		}
	}
    return 0;
}
