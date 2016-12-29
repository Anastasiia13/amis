#ifndef TEST_STUDENT_H
#define TEST_STUDENT_H

typedef struct Group{
    char name[10];
    int number_of_students;
};

typedef struct Student{
    char first_name[20];
    char last_name[20];
    char university_name[100];
    int course;
    char faculty_name[30];
    Group* group;
};

#endif //TEST_STUDENT_H
