#ifndef STRUCTFUN_H
#define STRUCTFUN_H
#include "struct.h"
Student create();
void   create_Student(Student *user);
void print (Student *user);
int getName(Student *user , char what[]);
int getSirname(Student *user , char what[]);
int getGroup(Student *user,char what[]);
int getBank(Student *user,char what[]);

#endif
