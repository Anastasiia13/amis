#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

typedef struct student {
    int number;
    char surname[20];
    char name[20];
    int  total_score;

}STUDENT;

typedef struct group {
    int number;
    char surname[20];
    char name[20];
    char group[10];
}GROUP;

int main(){

system ("cls");
STUDENT *students = NULL;
GROUP *groups = NULL;

students = (STUDENT *)malloc(sizeof(STUDENT));
groups = (GROUP *)malloc(sizeof(GROUP));

system("pause");

free(students) ;
free(groups);

return 0;
}
