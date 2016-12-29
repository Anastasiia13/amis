#include <stdio.h>
#include <stdlib.h>


#define max_leng 50
#define group_name_leng 10

typedef struct group{
    int  course;
    char group[group_name_leng];
} GROUP_S;
typedef struct student{
    char first_name[max_leng];
    char last_name[max_leng];
    GROUP_S * group_info;
} STUDENT;

typedef struct authorization{
    char login[max_leng];
    char password[max_leng];
} AUTH;
typedef struct lector{
    char first_name[max_leng];
    char last_name[max_leng];
    char subject[max_leng];
    int  mark;
    AUTH * auth_info;
} LECTOR;


int main()
{
    STUDENT * student=NULL;
    GROUP_S  * group=NULL;
    LECTOR * lector=NULL;
    AUTH * authorization=NULL;

    student=( STUDENT *)malloc(sizeof(STUDENT));
    group=( GROUP_S *)malloc(sizeof(GROUP_S));
    lector=( LECTOR *)malloc(sizeof(LECTOR));
    authorization=( AUTH *)malloc(sizeof(AUTH));

    strcpy(student->first_name,"Mike");
    strcpy(student->last_name,"Kurshakov");
    student->group_info=group;

    group->course=2;
    strcpy(group->group,"KM-53");

    lector->auth_info=authorization;
    strcpy(lector->first_name,"Ihor");
    strcpy(lector->last_name,"Tereshchenko");
    lector->mark=80;
    strcpy(lector->subject,"TKR PZ");

    strcpy(authorization->login,"LOGIN");
    strcpy(authorization->password,"PASSWORD");

    printf("Student: %s %s \n", student->first_name,student->last_name);
    printf("Course: %d Group: %s \n", student->group_info->course,student->group_info->group);
    printf("Lector: %s %s Mark: %d\n",lector->first_name,lector->last_name,lector->mark);
    printf("login: %s password: %s\n\n\n",lector->auth_info->login,lector->auth_info->password);

    getchar();

    free(student);
    free(group);
    free(lector);
    free(authorization);
    return 0;
}
