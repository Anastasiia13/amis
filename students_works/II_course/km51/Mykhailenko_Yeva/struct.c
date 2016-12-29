#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct abitur_info {
    char first_name[30];
    char last_name[30];
    char home_town[30];
    struct faculty_info *FACULTY;
    float result_zno;
    int age;
  }abitur_info;

  typedef struct univer_info {
    char name[30];
    char adress[30];
    float entrance_result;
  }univer_info;

  typedef struct faculty_info {
    char name[30];
    int studying_price;
    int budg_places;
    int total_places;
    struct univer_info *UNIVER;
  }faculty_info;

  typedef struct documents {
    char type[30];
    struct abitur_info *ABITUR;
  }documents;

  typedef struct dorm_info {
    char adress[30];
    int students_capacity;
    }dorm_info;

int main()
{
    abitur_info *abit1 = NULL;
    abit1 = (abitur_info *) malloc(sizeof(abitur_info));

    free(abit1);

    univer_info *uni1 = NULL;
    uni1 = (univer_info *) malloc(sizeof(univer_info));

    free(uni1);

    faculty_info *faculty1 = NULL;
    faculty1 = (faculty_info *) malloc(sizeof(faculty_info));

    free(faculty1);

    dorm_info *dorm1 = NULL;
    dorm1 = (dorm_info *) malloc(sizeof(dorm_info));

    free(dorm1);


    return 0;
}
