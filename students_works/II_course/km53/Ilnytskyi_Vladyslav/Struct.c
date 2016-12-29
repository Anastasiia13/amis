#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#define max_length 20

typedef struct Auth {
  char login[max_length];
  char password[max_length];
} Auth;

typedef struct Rating {
  int rating_of_abiturient;
  char privileges;
} Rating; 

struct Abiturient {
  char first_name;
  char last_name;
  char middle_name;
  int age;
  Rating *rating;
  Auth *authorization_info;
};

struct ZNO_task {
  int num_of_questions;
  int time_for_writing;
  char text_of_tasks;
};

typedef struct University {
  char name_of_university;
  int rating;
} university;

int validate(const char *s)
{
    while (*s) {
        if (isdigit(*s++) == 1) {
            return 0;}
    }
    return 1;
}

int validate_age(const char *s)
{
    while (*s) {
        if (isdigit(*s++) == 0) {
            return 0;}
    }
    return 1;
}

void register_user() {
  char buffer[32];
  Abiturient *abiturient = NULL;
  abiturient = (Abiturient*) malloc(sizeof(Abiturient));
  
  char *b = &abiturient->first_name;
  size_t bufsize = 32;
  size_t characters;
  
  printf( "\nPlease enter your name (only letters): ");
  getline(&b, &bufsize,stdin);
  int result = validate(&abiturient->first_name);
  if (result==1) {
    printf( "\nYou entered: ");
    puts(&abiturient->first_name);
  } else {
      printf( "Your entered name with digits, please enter real name!");
  }   
  
  char *last = &abiturient->last_name;
  
  printf( "\nPlease enter your last name (only letters): ");
  getline(&last, &bufsize,stdin);
  result = validate(&abiturient->last_name);
  if (result==1) {
    printf( "\nYou entered: ");
    puts(&abiturient->last_name);
  } else {
      printf( "Your entered last name with digits, please enter real name!");
  }   
  
  int num;
  char term;
  printf( "\nPlease enter your age (only digits): ");
  if(scanf("%d%c", &num, &term) != 2 || term != '\n')
    printf( "Your entered age with letters, please enter real age!");
  else {
    printf( "\nAbiturient saved! Great.");
    abiturient->last_name = num; }
  free(abiturient);
}

int main () {
    register_user();
    return 0;
}
