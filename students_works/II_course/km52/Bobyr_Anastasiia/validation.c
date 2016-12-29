#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define n 200

//definition of structures
struct tasktype {
char *task_question;
char *task_answers;
int task_grade;
};


struct user_student_type {
char *student_first_name;
char *student_last_name;
char *student_group;
};

struct user_teacher_type {
char *teacher_first_name;
char *teacher_last_name;
};

struct test_type {
int variant;
char *theme;
int count_of_tasks;
struct tasktype *task;
};

//validation functions
char *get_name() {
    char name[n];

          while ((scanf("%s", &name)==1)&& strlen(name)>200) {
          printf(" Something was wrong. You have to input string that includes maximum 200 symbols. Try again: ");
          fflush(stdin);}
        scanf("%s", name);
    return name;
}

char *get_group() {
    char my_group[n];
         while ((strcmp(my_group, "KM-51")!=0) ||(strcmp(my_group, "KM-52")!=0) || (strcmp(my_group, "KM-53")!=0))
         {scanf("%s",my_group);
         fflush(stdin);
         }
return my_group;
}

int get_int() {
    int number;
          while ((scanf("%d", &number)!=1)) {
          printf(" You can input only numbers. Try again: ");
          fflush(stdin);}
return number;
}


//main part
void main() {
struct user_student_type *user_student=NULL;
struct user_teacher_type *user_teacher=NULL;
struct test_type *test=NULL;

user_student=(struct user_student_type *)malloc(sizeof(struct user_student_type));
user_student->student_first_name=get_name();
user_student->student_last_name=get_name();
user_student->student_group=get_group();

user_teacher=(struct user_teacher_type *)malloc(sizeof(struct user_teacher_type));
user_teacher->teacher_first_name=get_name();
user_teacher->teacher_last_name=get_name();

test=(struct test_type *)malloc(sizeof(struct test_type));
test->theme=get_name();
test->count_of_tasks=get_int();
test->variant=get_int();
test->task->task_grade=get_int();
test->task->task_question=get_name();
test->task->task_answers=get_name();


free(user_student);
free(user_teacher);
free(test);
}
