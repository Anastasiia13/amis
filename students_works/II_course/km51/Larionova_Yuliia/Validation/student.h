#ifndef TEST_STUDENT_H
#define TEST_STUDENT_H

#define MAX_STUDENT_NAME_LENGTH 20
#define MAX_UNIVERSITY_NAME_LENGTH 20
#define MAX_FACULTY_NAME_LENGTH 20
#define MAX_GROUP_NAME_LENGTH 10

typedef struct Student{
    char first_name[MAX_STUDENT_NAME_LENGTH];
    char last_name[MAX_STUDENT_NAME_LENGTH];
    char university_name[MAX_UNIVERSITY_NAME_LENGTH];
    int course;
    char faculty_name[MAX_FACULTY_NAME_LENGTH];
    char group_name[MAX_GROUP_NAME_LENGTH];
};

Student* create_student();

#endif //TEST_STUDENT_H
