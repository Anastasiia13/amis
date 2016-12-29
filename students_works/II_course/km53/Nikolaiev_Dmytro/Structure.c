#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 
struct Test {
char task[100];
int timer;
enum {physics, math, english, german, ukrainian, biology, history, geography} subject;
int variant;
 };
 
typedef struct Enrollee {
char first_name[100];
char last_name[100];
char pass_info[100];
int state; //1 - registrated 0 - not registrated
struct Test * test;
 
 } Enrollee;


 
 int main ()
 {
  Enrollee *enrollee = NULL;
  enrollee = (Enrollee*) malloc(sizeof(Enrollee));
   strcpy(enrollee->first_name, "Dmitriy");
   strcpy(enrollee->last_name,  "Nikolaev");
   strcpy(enrollee->pass_info, "XDX84343XXW");
   enrollee->state=1;	
  printf("%s  %s  %s  %d" ,enrollee->first_name,enrollee->last_name,enrollee->pass_info,enrollee->state);
  free(enrollee);
  return 0;
 }
