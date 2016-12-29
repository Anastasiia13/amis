#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct STUDENT {
	char name[20];
	char last[20];
};

struct TEACHER {
	char name[20];
	char last[20];
};

struct laboratory_work {
	char variant[2];
	char count_of_done_tasks[2];
	struct STUDENT *info;	
};

struct student_info {
	struct STUDENT *info;
	int course[1];
	float rating_score[2];
};

struct student_group {
	char letters[2];
	char numbers[2];
};
struct teacher_info {
	struct TEACHER *info;
	char subject[20];
	int audience_number[3];
	int building_number[2];
	float mark[3];
};

int main () {
	
struct	student_info *student = NULL;
struct	laboratory_work *work = NULL;
struct	teacher_info *teacher = NULL;
	
	student_info *student_create() { 
		student = (struct student_info*) malloc(sizeof(struct student_info));
		student->info->name=get_name;
		student->info->last=get_last;
		student->course=get_course;
		student->rating_score=get_rating_score;
		return student;
	}
	
	char get_name(){
		int name_check = 0;
 		while (name_check == 0)
 			{
			 fflush(stdin);
			 printf("Enter your name (Example: Jane): ");
			 scanf("%s", &name);
			 
			 if (strchr(name, '0') || strchr(name, '1') || strchr(name, '2') || strchr(name, '3') || strchr(name, '4') || 
			 strchr(name, '5') || strchr(name, '6') || strchr(name, '7') || strchr(name, '8') || strchr(name, '9')){
			 printf("You input a number. Try again!\n");
			 beep(500, 500);
			 getchar();
			 system("cls");
			 }
			 else name_check = 1;
			 }		
	return name;	
	}
	
	char get_last(){
		int last_check = 0;
 		while (last_check == 0)
 			{
			 fflush(stdin);
			 printf("Enter your lastname (Example: Smith): ");
			 scanf("%s", &last);
			 
			 if (strchr(last, '0') || strchr(last, '1') || strchr(last, '2') || strchr(last, '3') || strchr(last, '4') || 
			 strchr(last, '5') || strchr(last, '6') || strchr(last, '7') || strchr(last, '8') || strchr(last, '9')){
			 printf("You input a number. Try again!\n");
			 beep(500, 500);
			 getchar();
			 system("cls");
			 }
			 else last_check = 1;
			 }		
	return last;	
	}
	
	int get_course(){
		int course_check = 0;
 		while (course_check == 0)
 			{
			 fflush(stdin);
			 printf("Enter your course (Example: 1): ");
			 scanf("%i", &course);
			 
			 if (strchr(last, '1') || strchr(last, '2') || strchr(last, '3') || strchr(last, '4') || 
			 strchr(last, '5') || strchr(last, '6')){
			 	course_check = 1;
			 }
			 else
			 	printf("You didn't input the right number. Try again!\n");
			 	beep(500, 500);
			 	getchar();
			 	system("cls"); 
			 }		
	return course;	
	}	
	
	float get_rating_score(){
		int score_check = 0;
 		while (score_check == 0)
 			{
			 fflush(stdin);
			 printf("Enter your rating score (Example: 15.5): ");
			 scanf("%f", &rating_score);
			 
			 if (strchr(last, '0') || strchr(last, '1') || strchr(last, '2') || strchr(last, '3') || strchr(last, '4') || 
			 strchr(last, '5') || strchr(last, '6') || strchr(last, '7') || strchr(last, '8') || strchr(last, '9') || strchr(last, '.')){
			 	score_check = 1;
			 }
			 else
			 	printf("You didn't input the right number. Try again!\n");
			 	beep(500, 500);
			 	getchar();
			 	system("cls"); 
			 }		
	return rating_score;	
	}	
	
	teacher = (struct teacher_info*) malloc(sizeof(struct teacher_info));
	work = (struct laboratory_work*) malloc(sizeof(struct laboratory_work));
	
	
	free(student);
	free(teacher);
	free(work);
	
	return 0;
	
}
