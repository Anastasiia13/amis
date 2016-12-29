#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef struct illness_history
{
	char doctor_name[20];
	char doctor_speciality[20];
	char sickness_name[20];
	int ending_date[3];
	char recepy[100];

}illnes_history[10];


typedef struct patient
{
	char first_name[20];
	char last_name[20];
	char job_address[20];
	int date[3];
	struct patient *next;
};




//перев≥рка введенн€ ≥мен≥
char* input_name()
{
    int input_check = 0;
	char name[20];
	while (input_check == 0)
	{
		fflush(stdin);
		printf("Enter your name(A a): ");
		scanf("%s", &name);
		if (strchr(name, '0') || strchr(name, '1') || strchr(name, '2') || strchr(name, '3') || strchr(name, '4') ||
			strchr(name, '5') || strchr(name, '6') || strchr(name, '7') || strchr(name, '8') || strchr(name, '9'))
		{
			printf("You input a number! Try again!\n");
			getchar();
			system("cls");
		}
		else input_check = 1;
	}
	//system("cls");
	return name;
}


//перев≥рка введенн€ пр≥звища
char* input_surname()
{
    int input_check = 0;
	char surname[20];
	while (input_check == 0)
	{
		fflush(stdin);
		printf("Enter your surname(A a): ");
		scanf("%s",&surname);
		if (strchr(surname, '0') || strchr(surname, '1') || strchr(surname, '2') || strchr(surname, '3') || strchr(surname, '4') ||
			strchr(surname, '5') || strchr(surname, '6') || strchr(surname, '7') || strchr(surname, '8') || strchr(surname, '9'))
		{
			printf("You input a number! Try again!\n");
			getchar();
			system("cls");
		}
		else input_check = 1;
	}
	system("cls");
	return surname;
}

//введенн€ числа
int input_day()
{
	int error;
	int date;

	do {
		fflush(stdin);
		printf("Day(1 -> 31): ");
		error = scanf("%i", &date);
		if ((date>31) || (date<1)) {
			printf("Invalid input! Try again!\n");
			getchar();
			error = 0;
		}
		else {
			error = 1;
		}
	} while ((error == 0));

	return date;
}

//введенн€ м≥с€ц€
int input_month()
{
	int error;
	int month;

	do {
		printf("Month(1 -> 12): ");
		fflush(stdin);
		error = scanf("%d", &month);
		if ((error == 0) || (month>12)) {
			fflush(stdin);

			printf("Invalid input! Try again!\n");
			getchar();
			error = 0;
		}
	} while ((error == 0));

	return month;
}

//введенн€ року
int input_year()
{	
	int error;
	int year;


	do {
		fflush(stdin);
		printf("Year(1920 -> 2016): ");
		error = scanf("%d", &year);
		if (error == 0 || year<1920 || year>2016)
		{
			printf("Invalid input! Try again!\n");
			getchar();
			error = 0;
		}
		fflush(stdin);
	} while (error == 0);


	return year;
}



int main(int argc, char *argv[])
{
	struct patient p, *pat = (struct patient*)malloc(sizeof(struct patient));
	//struct illness_history *ill = (struct illness_history*)malloc(sizeof(struct illness_history));
	int i, n;
	int error;


	strcpy(pat->first_name, input_name());
	fflush(stdin);

	strcpy(pat->last_name, input_surname());
	fflush(stdin);

	printf("Enter job address: ");
	gets(pat->job_address);
	
	system("cls");
	printf("Enter the date>\n");
	pat->date[0] = input_day();
	pat->date[1] = input_month();
	pat->date[2] = input_year();

	

	printf("\nFinish!");
	free(pat);
	//free(ill);
	_getch();
	return 0;
}
