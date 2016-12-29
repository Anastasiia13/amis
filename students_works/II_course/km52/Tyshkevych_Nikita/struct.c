#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct STUDENT {
	char name[20];
	char last[20];
};

struct credit_card {
	char cvv2[4];
	char card_number[16];
	struct STUDENT *info;	
};

struct student_info {
	struct STUDENT *info;
	char e_mail[40];
	char identf_number[12];
	float average_mark[];
};

int main () {
	
struct	student_info *student = NULL;
struct	credit_card *card = NULL;
	
	student = (struct student_info*) malloc(sizeof(struct student_info));
	card = (struct credit_card*) malloc(sizeof(struct credit_card));
	
	
	free(student);
	free(card);
	return 0;
	
}
