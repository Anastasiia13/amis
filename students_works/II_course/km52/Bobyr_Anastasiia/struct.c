#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define n 200

enum group {KM51, KM52, KM53};

struct tasktype {
char task_question[n];
char task_answers[n];
int task_grade;
};


struct user_student_type {
char student_first_name[n];
char student_last_name[n];
enum group student_group;
char student_nick[n];
char student_password[n];
};

struct user_teacher_type {
char teacher_first_name[n];
char teacher_last_name[n];
char teacher_nick[n];
char teacher_password[n];
};

struct test_type {
int variant;
char theme[n];
int count_of_tasks;
struct tasktype *task;
};


void main() {
struct user_student_type *user_student;
struct user_teacher_type *user_teacher;
struct test_type *test;

user_student=(struct user_student_type *)malloc(sizeof(struct user_student_type));
user_teacher=(struct user_teacher_type *)malloc(sizeof(struct user_teacher_type));
test=(struct test_type *)malloc(sizeof(struct test_type));

free(user_student);
free(user_teacher);
free(test);
}
