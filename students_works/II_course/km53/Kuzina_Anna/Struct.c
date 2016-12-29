#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct Group{
    char name[10];
    int number_of_students;
};


struct user_student_type {
    char student_first_name[20];
    char student_last_name[20];
    char student_nick[40];
    char student_password[40];
    struct Group* group;
};

struct user_lecturer_type {
    char lecturer_first_name[20];
    char lecturer_last_name[20];
    char lecturer_nick[40];
    char lecturer_password[40];
};

struct test_type {
    int variant;
    char theme[500];
    int count_of_tasks;
    char task_question[40];
};


void main() {
struct user_student_type *user_student;
struct user_lecturer_type *user_lecturer;
struct test_type *test;
struct Group* group;

user_student=(struct user_student_type *)malloc(sizeof(struct user_student_type));
user_lecturer=(struct user_lecturer_type *)malloc(sizeof(struct user_lecturer_type));
test=(struct test_type *)malloc(sizeof(struct test_type));
group=(struct Group *)malloc(sizeof(struct Group));

free(user_student);
free(user_lecturer);
free(test);
free(group);
}
