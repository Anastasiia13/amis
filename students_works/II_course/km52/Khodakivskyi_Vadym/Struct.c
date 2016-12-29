#include <stdio.h>
#include <stdlib.h>
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

struct statement * creat_statement(struct statement * statement);
struct statement * print_statement(struct statement * head);
 int delete_statement(struct statement * statement);

 int main(){
    struct statement statement;
    delete_statement(print_statement(creat_statement(&statement)));
    return 0;
 }

struct statement * creat_statement(struct statement * statement){
    struct statement * head = NULL;
    struct statement * prev, * current;
    char k;
    printf("esc to exit! any key to continue \n");
    k=getch();
    while(k!=27){
        struct statement * current = (struct statement *)malloc(sizeof(struct statement));
        if (head==NULL)
            head = current;
        else
        {
            (*prev).next = current;
            (*current).next = NULL;
        }
        printf("Enter name surname university faculty department \n");
        scanf("%s %s %s %s %s",(*current).student.first_name,(*current).student.last_name,(*current).university, (*current).faculty, (*current).department);
        printf("\n");
        prev = current;
        printf("esc to exit! any key to continue\n");
        k=getch();
    }

    return head;
};
struct statement * print_statement(struct statement * head){
    int count = 1;
    if (head == NULL)
		return 0;
	struct statement * current = head;
	while (current != NULL){
		printf("   name    surname   university   faculty    department \n");
		printf(" %s " " %s " " %s " " %s " " %s ", (*current).student.first_name,(*current).student.last_name,(*current).university, (*current).faculty, (*current).department);
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

