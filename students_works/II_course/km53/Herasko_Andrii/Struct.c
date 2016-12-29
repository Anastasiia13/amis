#include <stdio.h>
#include <string.h>

struct Author {
	char name[20];
	int course;
	char group[6];
}

struct Course_project {
	Author* author;
	char topic[30]; //тема
	char date[10]; //дата сдачи 
}

int main()
{  
   Author *A = NULL;
   Course_project *B = NULL;

   A = (Author*)malloc(sizeof(Author));
   B = (Course_project*)malloc(sizeof(Course_project));


   A->course=2;
   strcpy(A->group,"km-53");
   strcpy(A->name,"Andrei");

   
   B->author=A;
   strcpy(B->date,"30.11.2016");
   strcpy(B->topic,"tema");

   free(A);
   free(B);

   return 0;
}