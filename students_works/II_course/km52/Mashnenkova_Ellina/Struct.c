#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct teacher {
char name1[20];
char surename1[20];
};

struct student {
char name2[20];
char surename2[20];
char group[10];
};

struct laboratory_work {
char theme[100];
int number_of_variant;
char aim[200];
char tasks[200];
int count_of_tasks;
char test_questions[200];
int count_of_questions;
int grade;
};

void main() {
struct student *st;
struct teacher *teach;
struct laboratory_work *lab;
st=(struct student *)malloc(sizeof(struct student));
teach=(struct teacher *)malloc(sizeof(struct teacher));
lab=(struct laboratory_work *)malloc(sizeof(struct laboratory_work));
free(st);
free(teach);
free(lab);
}

