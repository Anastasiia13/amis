#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAXLENGTH 100
        struct Location {
        char street[MAXLENGTH];
        char house_number[MAXLENGTH];
};
    struct Bank {
      struct Location *location;
      char bank_name[MAXLENGTH];

};
    struct Card {
       char serial_number[MAXLENGTH];
       int balance;
       char firts_name[MAXLENGTH];
       char second_name[MAXLENGTH];
       struct Bank * bank;

};
  typedef struct Student {
     char first_name[MAXLENGTH];
     char last_name[MAXLENGTH];
     int average_point;
     struct Card *card;

}Student;
int main ()
{
 Student *new_student = NULL;
 new_student = (Student*) malloc(sizeof(Student));
  strcpy(new_student->first_name, "Artem");
  strcpy(new_student->last_name,  "Usenko");

 printf("%s  %s",new_student->first_name,new_student->last_name);
 free(new_student);
 return 0;
}
