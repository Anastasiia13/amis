#ifndef _STUDENT_H_
#define _STUDENT_H_

#define MAX_NAME_LENGTH 10
#define MAX_GROUP_CIPHER_LENGTH 10

struct Student{
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    int course_number;
    char group_cipher[MAX_GROUP_CIPHER_LENGTH];
};

struct Student* create student();

char* get_student_first_name();
char* get_student_last_name();
char* get_student_group_chipher();
int get_student_course_number();


#endif
