#include <conio.h>
#include <stdio.h>

struct Student {
  char[] first_name;
  char[] last_name;
  char[] middle_name;
  struct Gradebook *gradebook;
  int age;
  bool access;
  int score;
};

struct  Lecturer {
  char[] first_name;
  char[] last_name;
  char[] middle_name;
  char[] position;
};

struct WorkFile {
  struct File *paper;
  struct Work *work;
  struct CommentBox *comment_box;
};

typedef struct Examination {
  char[] first_name;
  char[] last_name;
  double time_for_work;
  struct WorkFile *work_file;
} Examination;

int main () {
  Examination *examination = NULL;
  examination = (Examination*) malloc(sizeof(Examination));
  strcpy(examination->first_name, "Vadym");
  strcpy(examination->last_name,  "Hevlich");
  strcpy(examination->time_for_work,  2.5);
  
  printf("%s %s %d", examination->first_name, examination->last_name,
         examination->time_for_work);
  free(examination);
  return 0;
}