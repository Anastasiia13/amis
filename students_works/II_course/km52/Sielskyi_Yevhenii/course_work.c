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

int main (void) {
	struct student_info {
   		char name[30];
    	char surname[50];
    	char group[10];
    } students[15];
    
    struct theme {
   		char theme_name[50];
    	bool origin;
    } themes[15];
    
    struct teacher_info {
   		char name[30];
    	char surname[50];
    } teachers[15];
    
    struct mark {
   		struct student_info;
    	int student_mark;
    } marks[15];
    
    struct report {
    	struct theme;
    	struct mark;
	} reports[15];
	
	char Key, Key1;
	int s = 0, t = 0, tc = 0, m = 0;
	while (1) {
		setlocale(LC_ALL, "rus");
		system("cls");
	    printf("________________________________________________________________________________");
	    printf("|                            ��������� �������� ������                         |");
	    printf("|                        �����: �������� �., ������: ��-52                     |");
	    printf("|______________________________________________________________________________|");
	    gotoxy(25, 8);
	    printf("'1' - �������� ��������");
	    gotoxy(25, 9);
	    printf("'2' - �������� ����");
	    gotoxy(25, 10);
	    printf("'3' - �������� �������������");
	    gotoxy(25, 11);
	    printf("'4' - �������� ������");
	    gotoxy(25, 12);
	    printf("'5' - ������� ��� ������");
	    gotoxy(34, 13);
	    printf("'Esc' - �����");
	    Key = getch();   
		while (Key != '1' && Key != '2' && Key != '3' && Key != '4' && Key != '5' && Key != 27) {
	        system("cls");
	        printf("________________________________________________________________________________");
		    printf("|                            ��������� �������� ������                         |");
		    printf("|                        �����: �������� �., ������: ��-52                     |");
		    printf("|______________________________________________________________________________|");
		    SetColor(4, 0);
		    gotoxy(25, 8);
		    printf("'1' - �������� ��������");
		    gotoxy(25, 9);
		    printf("'2' - �������� ����");
		    gotoxy(25, 10);
		    printf("'3' - �������� �������������");
		    gotoxy(25, 11);
		    printf("'4' - �������� ������");
		    gotoxy(25, 12);
		    printf("'5' - ������� ��� ������");
		    gotoxy(34, 13);
		    printf("'Esc' - �����");
		    SetColor(7, 0);
	    	Key = getch();
		}
		if (Key == '1') {
			system("cls");
			printf("������� ��� ��������:");
	        gets(students[s].name);
	        while(strlen(students[s].name) < 2 || strlen(students[s].name) > 30){
	        	system("cls");
				SetColor(4, 0);
				printf("������� ��� ��������:");
				SetColor(7, 0);
				gets(students[s].name);
			}
			gotoxy(0, 0);
			SetColor(7, 0);
			gotoxy(0, 1);
			printf("������� ������� ��������:");
	        gets(students[s].surname);
	        while(strlen(students[s].surname) < 2 || strlen(students[s].surname) > 30){
	        	system("cls");
				SetColor(4, 0);
				printf("������� ������� ��������:");
				SetColor(7, 0);
				gets(students[s].surname);
			}
			gotoxy(0, 1);
			SetColor(7, 0);
			gotoxy(0, 2);
			printf("������� ������:");
	        gets(students[s].group);
	        while(strlen(students[s].group) < 2 || strlen(students[s].group) > 30){
	        	system("cls");
				SetColor(4, 0);
				printf("������� ������:");
				SetColor(7, 0);
				gets(students[s].group);
			}
			s++;
		}
		else if (Key == '2') {
			system("cls");
			printf("������� �������� ����:");
	        gets(themes[t].theme_name);
	        while(strlen(themes[t].theme_name) > 50){
	        	system("cls");
				SetColor(4, 0);
				printf("������� �������� ����:");
				SetColor(7, 0);
	       		gets(themes[t].theme_name);
			}
			gotoxy(0, 0);
			SetColor(7, 0);
			themes[t].origin = true;
			t++;
		}
		else if (Key == '3') {
			system("cls");
			printf("������� ��� �������������:");
	        gets(teachers[tc].name);
	        while(strlen(teachers[tc].name) < 2 || strlen(teachers[tc].name) > 30){
	        	system("cls");
				SetColor(4, 0);
				printf("������� ��� �������������:");
				SetColor(7, 0);
				gets(teachers[tc].name);
			}
			gotoxy(0, 0);
			SetColor(7, 0);
			gotoxy(0, 1);
			printf("������� ������� �������������:");
	        gets(teachers[tc].surname);
	        while(strlen(teachers[tc].surname) < 2 || strlen(teachers[tc].surname) > 30){
	        	system("cls");
				SetColor(4, 0);
				printf("������� ������� �������������:");
				SetColor(7, 0);
				gets(teachers[tc].surname);
			}
			gotoxy(0, 1);
			SetColor(7, 0);
			tc++;
		}
		else if (Key == '4') {
			system("cls");
			printf("������� ������ �������� �%d:", m+1);
	        while(scanf("%d", &marks[m].student_mark)!=1 || marks[m].student_mark < 0 || marks[m].student_mark > 100){
	        	system("cls");
				SetColor(4, 0);
				printf("������� ������ �������� �%d:", m);
				SetColor(7, 0);
				fflush(stdin);
			}
			gotoxy(0, 0);
			SetColor(7, 0);
			m++;
		}
		else if (Key == '5') {
			int i;
			system("cls");
			printf("��������:");
			for(i = 0; i < s; i++) {
				puts(students[i].name);
				puts(students[i].surname);
				puts(students[i].group);
			};
	        printf("����:");
	        for (i = 0; i < t; i++) {
				puts(themes[i].theme_name);
				if (themes[i].origin)
					printf("���� �� ��������� \n");
				else
					printf("���� ���������� ��������� \n");	
			};
			printf("�������������:");
	        for (i = 0; i < tc; i++) {
				puts(teachers[i].name);
				puts(teachers[i].surname);	
			};
			printf("������:");
	        for (i = 0; i < m; i++) {
				puts(students[i].name);
				puts(students[i].surname);
				puts(students[i].group);
				printf("%d", marks[i].student_mark);
			};
	        getch();
		}
		else if (Key == 27)
			break;
	}
    return 0;
}
