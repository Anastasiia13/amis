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
	char group[5];
	int course[1];
	float rating_score[2];
};

struct teacher_info {
	struct TEACHER *info;
	char subject[20];
	int audience_number[3];
	int building_number[2];
	float mark[2];
};

int main () {
	
struct	student_info *student = NULL;
struct	laboratory_work *work = NULL;
struct	teacher_info *teacher = NULL;
	
	student = (struct student_info*) malloc(sizeof(struct student_info));
	teacher = (struct teacher_info*) malloc(sizeof(struct teacher_info));
	work = (struct laboratory_work*) malloc(sizeof(struct laboratory_work));
	
	
	free(student);
	free(teacher);
	free(work);
	return 0;
	
}
