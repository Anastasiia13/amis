#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct Author {
	char name[40];
	int course;
	char group[11];
};

struct Course_project {
	Author* author;
	char topic[30]; //тема
	char date[11]; //дата сдачи 
};

char* get_stud_name(){
	char *fname = (char *)malloc(sizeof(char)*40);
	char *lname = (char *)malloc(sizeof(char)*20);
	printf("get first name \n");
	try {
		gets(fname);
	}
	catch (...)
  {
    printf("mnogo simvolov!!! ili drugaya oshibka)");
	return get_stud_name();
  };
	if (strlen(fname)<2 || strlen(fname)>20) {
		printf("korotkoe ili dlinoe imya!!");
		return get_stud_name();
	};
	printf("get last name \n");
	try {
		gets(lname);
	}
	catch (...)
  {
    printf("mnogo simvolov!!! ili drugaya oshibka)");
	return get_stud_name();
  };
	if (strlen(lname)<2) {
		printf("korotkoe imya!!");
		return get_stud_name();
	};
	return strcat(fname, lname);
};

int get_stud_course(){
	char course[1];
	int a = -1;
	printf("vvedite kusr (1-5)");
	try {
		gets(course);
		a = atoi(course);
	}
	catch (...) {
    printf("mnogo simvolov!!! ili ne int");
	return get_stud_course();
  };
	if (a<1 || a>5) {
		return get_stud_course();
	};
	return a;
};
char* get_stud_group(){
	char *group = (char *)malloc(sizeof(char)*10);
	printf("get group");
	try {
		gets(group);
	}
	catch (...)
  {
    printf("mnogo simvolov!!! ili drugaya oshibka)");
	return get_stud_group();
  };
	
	return group;
};

char* get_topic(){
	char *topic = (char *)malloc(sizeof(char)*30);
	printf("get group");
	try {
		gets(topic);
	}
	catch (...)
  {
    printf("mnogo simvolov!!! ili drugaya oshibka)");
	return get_topic();
  };
	
	return topic;
};


int main()
{  
 struct Author *A = NULL;
 struct Course_project *B = NULL;

   A = (Author*)malloc(sizeof(Author));
   B = (Course_project*)malloc(sizeof(Course_project));
   
A->course = get_stud_course();
strcpy(A->group, get_stud_group());
strcpy(A->name, get_stud_name());

B->author=A;
strcpy(B->topic, get_topic());

   free(A);
   free(B);
   return 0;
}