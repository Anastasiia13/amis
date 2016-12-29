#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 
typedef struct Test {
char task[200];
int timer;
enum {physics, math, english, german, ukrainian, biology, history, geography} subject;
int variant;
 } Test;
 
typedef struct Enrollee {
char first_name[100];
char last_name[100];
char pass_num[100];
struct Test * test;
 
 } Enrollee;

char *set_name()
{
	int i;
	char string [20];
	int correct=0;
	fflush(stdin);
	char invalid[]="~1234567890-=!@#$%^&*()_+";
	while(correct!=1)
	{
		fflush(stdin);
		
		scanf("%s",string);
		for (i=0;string[i]!='\0';i++)
		{
		
		if (strchr(invalid,string[i]))
		{
			printf("Invalid Input!\nTry again: ");
			correct=0;
			break;
		}
		else
		{
			
			 correct=1;
			 break;
		}
		
	}
	

}
system("cls");
return string;
}

char *set_passnum()
{
	int i;
	char string [20];
	int correct=0;
	fflush(stdin);
	char invalid[]="~-=!@#$%^&*()_+";
	printf("Enter enrollee's pass number: ");
	while(correct!=1)
	{
		fflush(stdin);
		
		scanf("%s",string);
		for (i=0;string[i]!='\0';i++)
		{
		
		if (strchr(invalid,string[i]))
		{
			printf("Invalid Input!\nTry again: ");
			correct=0;
			break;
		}
		else
		{
			
			 correct=1;
			 break;
		}
		
	}
	

}
system("cls");
return string;
}
 

 int set_timer()
 {
     int time;
     int correct=0;
     printf("Enter time for test (in minutes): ");
     while(correct==0) {
 		
 		correct = scanf("%d", &time);
 		if((time <90) || (time > 400)){
              printf("90 m > Time < 400 m\n");
              correct = 0;
              fflush(stdin);
         }
 		else{
 		correct = 1;
 		}
 	} 
     return time;
 }
 
 
 int set_variant()
 {
 	int var;
 	fflush(stdin);
 	printf("Enter enrollee's variant: ");
 	while(1)
 	if (scanf("%d",&var)!=0)
 	{
 		break;
 	}
 	else
 	{
 		printf("Not valid input. Enter a number or a digit\n");
 		fflush(stdin);
 		
 	}
 	return var;
 }
 

 int main ()
 {
  Enrollee *enrollee = NULL;
  enrollee = (Enrollee*) malloc(sizeof(Enrollee));
	printf("Name: ");
   strcpy(enrollee->first_name, set_name());
   printf("Lastname: ");
   strcpy(enrollee->last_name,  set_name());
   strcpy(enrollee->pass_num, set_passnum());
   enrollee->test=(Test*) malloc (sizeof(Test));
   enrollee->test->timer=set_timer();
   enrollee->test->variant=set_variant();
   
   system("cls"); 
  printf("Name: %s\nLast Name: %s\nPassport number: %s\nTime: %d\nVariant: %d\n" ,enrollee->first_name,enrollee->last_name,enrollee->pass_num, enrollee->test->timer,enrollee->test->variant);
  free(enrollee);
  return 0;
 }
