#include <stdio.h>
#include <stdlib.h>

enum Subjects{
    TOCD,
    PHYSICS,
    MATH,
    MATHEMATICAL_ANALYSIS,
    ENGLISH
};

double inputNumber() {		//if entered data is incorrect returns 0;
	fflush(stdin);


	int scan;
	return  scanf("%d",&scan)!=1 || scan < 0  ? IncorrectInputError() : scan;
}

void IncorrectInputError()	{
	printf("\nYou entered incorrect value.\nPlease enter a number bigger than zero\n");
	inputNumber();
}

struct Student {
    int number_in_list;     //Number of student in the list
    char name[20];
    char group[5];
    int visits;
    float average_mark;
};

struct Elder_student {
    int number_in_list;
    char name[20];
    char group[5];
    int visits;
    float average_mark;
    int visits_list[30];        //Array of student's visits
};

struct Teacher  {
    char name[20];
    enum Subjects subject;
    float marks_list[30];        //Array of student's marks on this subject
};

fillStudentForm(struct Student *student)	{
	printf("Enter student's number in list : ");
	student[0].number_in_list =(int)inputNumber();
	fflush(stdin);
	printf("Enter student's name : ");
	fgets(student[0].name,20,stdin);
	printf("Enter student's group : ");
	fgets(student[0].group,5,stdin);
	printf("Enter student's visits : ");
	student[0].visits =(int) inputNumber();
	printf("Enter student's average mark : ");
	student[0].average_mark =(int) inputNumber();
}

fillElderStudentForm(struct Elder_student *student)	{
	printf("Enter student's number in list : ");
	student[0].number_in_list =(int)inputNumber();
	fflush(stdin);
	printf("Enter student's name : ");
	fgets(student[0].name,20,stdin);
	printf("Enter student's group : ");
	fgets(student[0].group,5,stdin);
	printf("Enter student's visits : ");
	student[0].visits =(int) inputNumber();
	printf("Enter student's average mark : ");
	student[0].average_mark =(int) inputNumber();
}

int inputSubject()	{
	printf("Please enter number from 0 to 5 : \n0 = TOCD\n1 = PHYSICS");
    printf("\n2 = MATH\n3 = MATHEMATICAL_ANALYSIS\n4 = ENGLISH\n ");
	int sub = inputNumber();
	return sub<5 ? sub : inputSubject();
}

fillTeacherForm(struct Teacher *teacher)	{
	printf("Enter teacher's name : ");
	fgets(teacher[0].name,20,stdin);
	teacher[0].subject = inputSubject();
}

int main()	{
	struct Student *student = (struct Student*)malloc(sizeof(struct Student));
	fillStudentForm(student);
	struct Elder_student *elder = (struct Elder_student*)malloc(sizeof(struct Elder_student));
	fillElderStudentForm(elder);
	struct Teacher *teacher = (struct Teacher*)malloc(sizeof(struct Teacher));
	fillTeacherForm(teacher);
    return 0;
}

