#include<stdio.h>
#include "windows.h"
#include<conio.h>
#include<malloc.h>
#include<string.h>

typedef struct Examiner
{
	char surname[40];
	char name[40];
	char father_name[40];
	struct Examiner *next;
} examiner;

examiner *head=NULL;

void gotoxy(int xpos, int ypos)
{
	COORD scrn;    
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput,scrn);
}

void textcolor(int text)
{
   HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut,(WORD)(text));
}

examiner *new_examiner();

void add_new_examiner(examiner *);

void list();

void free_memory();

void menu()
{
	char key;
	while(1)
	{
		textcolor(15);
		system("cls");
		printf("\n 1) Press '1' to add new examiner in the list");
		printf("\n 2) Press '2' to show the list of examiners");
		printf("\n 3) Press 'ESC' to quit");
		printf("\n\n Press the necessary key: ");
		key=getch();
		switch(key)
		{
			case '1':
				add_new_examiner(new_examiner());
				break;
			case '2':
				list();
				break;
			case 27:
				free_memory();
				exit(0);
			default:
				gotoxy(1,5);
				textcolor(12);
				printf("Press the necessary key: ");
				Sleep(100);
				break;
		}
	}
}

examiner *new_examiner()
{
	examiner *element=(examiner*)malloc(sizeof(examiner));
	while(1)
	{
		system("cls");
		textcolor(15);
		printf("\n Enter the surname of examiner: ");
		gets(element->surname);
		if(strlen(element->surname)>40)
		{
			system("cls");
			textcolor(12);
			printf("\n Enter the surname of examiner: ");
			Sleep(100);
		}
		else
			break;
	}
	while(1)
	{
		system("cls");
		textcolor(15);
		printf("\n Enter the name of examiner: ");
		gets(element->name);
		if(strlen(element->name)>40)
		{
			system("cls");
			textcolor(12);
			printf("\n Enter the name of examiner: ");
			Sleep(100);
		}
		else
			break;
	}
	while(1)
	{
		system("cls");
		textcolor(15);
		printf("\n Enter the father_name of examiner: ");
		gets(element->father_name);
		if(strlen(element->father_name)>40)
		{
			system("cls");
			textcolor(12);
			printf("\n Enter the father_name of examiner: ");
			Sleep(100);
		}
		else
			break;
	}
	return element;
}

void add_new_examiner(examiner *element)
{
	examiner *current;
	if(head==NULL)
	{
		element->next=NULL;
		head=element;
	}
	else
	{
		current=head;
		while(current->next!=NULL)
			current=current->next;
		current->next=element;
		element->next=NULL;
	}
	system("cls");
	return;
}

void list()
{
	if(head==NULL)
	{
		system("cls");
		printf("\n\n  Empty list");
		printf("\n\n  Press any key");
		getch();
		return;
	}
	int counter=1;
	examiner *tmp=head;
	system("cls");
	while(tmp!=NULL)
	{
		printf("\n %d) %s %s %s",counter,tmp->surname,tmp->name,tmp->father_name);
		tmp=tmp->next;
		counter+=1;
	}
	printf("\n\n Press any key");
	getch();
	return;
}

void free_memory()
{
	if(head==NULL)
		return;
	examiner *prev=head;
	while(prev!=NULL)
	{
		head=prev;
		prev=prev->next;
		free(head);
		head=NULL;
	}
}

int main()
{
	menu();
}
