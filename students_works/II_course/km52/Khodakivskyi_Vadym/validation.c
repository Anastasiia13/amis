#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define name 15
#define VNZ 20
struct applicant{
    char first_name[name];
    char last_name[name];
};
struct statement{
    struct applicant student;
    char university[VNZ];
    char faculty[VNZ];
    char department[VNZ];
    struct statement * next;
 };
 struct statement * head, * current, * prev;

struct statement * creat_statement(struct statement * statement);
struct statement * print_statement(struct statement * head);
int delete_statement(struct statement * statement);
char enter_first_name();
char enter_last_name();
char enter_university();
char enter_faculty();
char enter_department();
 int main(){
    struct statement statement;
    delete_statement(print_statement(creat_statement(&statement)));
    return 0;
 }

struct statement * creat_statement(struct statement * statement){
    head = NULL;
    char k;
    int i=0;
    printf("esc to exit! any key to continue \n");
    k=getch();
    while(k!=27){
        current = (struct statement *)malloc(sizeof(struct statement));
        if (head==NULL)
            head = current;
        else
        {
            (*prev).next = current;
            (*current).next = NULL;
        }
        printf("Enter your name (first letter must be big!!!)\n\n");
        enter_first_name();
        printf("Enter your surname (first letter must be big!!!)\n\n");
        enter_last_name();
        printf("Enter name of university (first letter must be big!!!)\n\n");
        enter_university();
        printf("Enter name of faculty (first letter must be big!!!)\n\n");
        enter_faculty();
        printf("Enter name of department (first letter must be big!!!)\n\n");
        enter_department();
        printf("\n");
        prev = current;
        printf("esc to exit! any key to continue\n");
        k=getch();
    }
    return head;
    }
struct statement * print_statement(struct statement * head){
    int count = 1;
    if (head == NULL)
		return 0;
	 current = head;
	while (current != NULL){
		printf("         name           surname         university             faculty             department  \n");
		printf("%15s" "%15s" "%20s" "%20s" "%20s" , (*current).student.first_name,(*current).student.last_name,(*current).university,(*current).faculty,(*current).department);
		printf("\n");
		current = (*current).next;
	}
	return head;
}

int delete_statement(struct statement * head){
    if (head == NULL)
		return 0;
	struct statement * current = head;
	while (current != NULL){
		free(current);
		current = current->next;
	}
	return 0;
	}

char enter_first_name(){
    char let;
    int i=0;

    while ((let = getche()) != 13 && i < name-1){
            if (i==0){
               if (let < 65 || let > 90) {
                    printf("  << you enter an invlid symbol!!! \n");
                    }
               else {(*current).student.first_name[0]=let;i++;}
            }
            else{
                    if (let < 97 || let > 122) {
                        printf("  << you enter an invlid symbol!!! \n");
                    }
                    else{
                        (*current).student.first_name[i]=let;
                        i++;
                    }
            }
      }
printf("\n");
    return (*current).student.first_name;
}

char enter_last_name(){
    char let;
    int i=0;

    while ((let = getche()) != 13 && i < name-1){
            if (i==0){
               if (let < 65 || let > 90) {
                    printf("  << you enter an invlid symbol!!! \n");
                    }
               else {(*current).student.last_name[0]=let;i++;}
            }
            else{
                    if (let < 97 || let > 122) {
                        printf("  << you enter an invlid symbol!!! \n");
                    }
                    else{
                        (*current).student.last_name[i]=let;
                        i++;
                    }
            }
      }
printf("\n");
    return (*current).student.last_name;
}
 char enter_university(){
    char let;
    int i=0;

    while ((let = getche()) != 13 && i < VNZ-1){
            if (i==0){
               if (let < 65 || let > 90) {
                    printf("  << you enter an invlid symbol!!! \n");
                    }
               else {(*current).university[0]=let;i++;}
            }
            else{
                    if (let < 97 || let > 122) {
                        printf("  << you enter an invlid symbol!!! \n");
                    }
                    else{
                        (*current).university[i]=let;
                        i++;
                    }
            }
      }
printf("\n");
    return (*current).university;
}

char enter_faculty(){
    char let;
    int i=0;

    while ((let = getche()) != 13 && i < VNZ-1){
            if (i==0){
               if (let < 65 || let > 90) {
                    printf("  << you enter an invlid symbol!!! \n");
                    }
               else {(*current).faculty[0]=let;i++;}
            }
            else{
                    if (let < 97 || let > 122) {
                        printf("  << you enter an invlid symbol!!! \n");
                    }
                    else{
                        (*current).faculty[i]=let;
                        i++;
                    }
            }
      }
printf("\n");
    return (*current).faculty;
}

char enter_department(){
    char let;
    int i=0;

    while ((let = getche()) != 13 && i < VNZ-1){
            if (i==0){
               if (let < 65 || let > 90) {
                    printf("  << you enter an invlid symbol!!! \n");
                    }
               else {(*current).department[0]=let;i++;}
            }
            else{
                    if (let < 97 || let > 122) {
                        printf("  << you enter an invlid symbol!!! \n");
                    }
                    else{
                        (*current).department[i]=let;
                        i++;
                    }
            }

      }
        printf("\n");
    return (*current).department;
}


