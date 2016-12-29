#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


struct illness_history
{
	char doctor_name[20];
	char doctor_speciality[20];
	char sickness_name[20];
	int ending_date[3];
	char recepy[100];

};

struct patient
{
	char first_name[20];
	char last_name[20];
	char job_address[20];
	int date[3];
};



int main()
{
	patient *pat = NULL;
	illness_history *ill = NULL;




	return 0;
}
