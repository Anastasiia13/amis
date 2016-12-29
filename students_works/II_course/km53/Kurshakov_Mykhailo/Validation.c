#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>



#define max_leng 50
#define group_name_leng 10

typedef struct group_s{
    int  course;
    char group_name[group_name_leng];
} GROUP_S;
typedef struct student_s{
    char first_name[max_leng];
    char last_name[max_leng];
    GROUP_S * group_info;
} STUDENT;

typedef struct authorization_s{
    char login[max_leng];
    char password[max_leng];
} AUTH;
typedef struct lector_s{
    char first_name[max_leng];
    char last_name[max_leng];
    char subject[max_leng];
    int  mark;
    AUTH * auth_info;
} LECTOR;

void Create_student(STUDENT *student);
char * Get_name(void);
void Create_group(GROUP_S * group);
char * Get_group_name(void);
int Get_course(void);
int Get_mark(void);
void Create_lector(LECTOR * lector);
void Create_authorization(AUTH * authorization);
char * Get_auth();
void Show_information(STUDENT * student,LECTOR * lector);

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

    student->group_info=group;
    lector->auth_info=authorization;

    Create_student(student);
    Create_group(group);
    Create_lector(lector);
    Create_authorization(authorization);

    system("cls");

    Show_information(student,lector);
    getchar();
    free(student->group_info);
    free( lector->auth_info);
    free(student);
    free(group);
    free(authorization);
    free(lector);
    return 0;
}
void Create_student(STUDENT *student)
{
    char * p_buf;
    strcpy(student->first_name,"\0");
    strcpy(student->last_name,"\0");
    while(!strcmp(student->first_name,"\0"))
    {
    printf("\nEnter first name of student->");
    p_buf=Get_name();
    strcpy(student->first_name,p_buf);
    free(p_buf);
    system("cls");
    }
    while(!strcmp(student->last_name,"\0"))
    {
    printf("\nEnter last name of student->");
    p_buf=Get_name();
    strcpy(student->last_name,p_buf);
    free(p_buf);
    system("cls");
    }

}
void Create_group(GROUP_S * group)
{
    char * p_buf;
    group->course=-1;
    strcpy(group->group_name,"\0");
    while(!strcmp(group->group_name,"\0"))
    {
    printf("\nEnter group name ->");
    p_buf=Get_group_name();
    strcpy(group->group_name,p_buf);
    free(p_buf);
    system("cls");
    }
    while(group->course==-1)
    {
    printf("\nEnter course ->");
    group->course=Get_course();
    system("cls");
    }
}
void Create_lector(LECTOR * lector)
{
    char * p_buf;
    lector->mark=-1;
    strcpy(lector->first_name,"\0");
    while(!strcmp(lector->first_name,"\0"))
    {
    printf("\nEnter first name of lector ->");
    p_buf=Get_name();
    strcpy(lector->first_name,p_buf);
    free(p_buf);
    system("cls");
    }
    strcpy(lector->last_name,"\0");
    while(!strcmp(lector->last_name,"\0"))
    {
    printf("\nEnter last name of lector  ->");
     p_buf=Get_name();
    strcpy(lector->last_name,p_buf);
    free(p_buf);
    system("cls");
    }
    strcpy(lector->subject,"\0");
    while(!strcmp(lector->subject,"\0"))
    {
    printf("\nEnter subject ->");
     p_buf=Get_name();
    strcpy(lector->subject,p_buf);
    free(p_buf);
    system("cls");
    }
    while(lector->mark==-1)
    {
    printf("\nEnter mark ->");
    lector->mark=Get_mark();
    system("cls");
    }
}
void Create_authorization(AUTH * authorization)
{
    char * p_buf;
    strcpy(authorization->login,"\0");
    strcpy(authorization->password,"\0");
    while(!strcmp(authorization->login,"\0"))
    {
    printf("\nEnter login ->");
     p_buf=Get_auth();
    strcpy(authorization->login,p_buf);
    free(p_buf);
    system("cls");
    }
    while(!strcmp(authorization->password,"\0"))
    {
    printf("\nEnter password ->");
     p_buf=Get_auth();
    strcpy(authorization->password,p_buf);
    free(p_buf);
    system("cls");
    }
}
char *  Get_name(void)
{
  char buf[max_leng*2];
  char * p_buf;
  int i=0,j;
  fflush(stdin);
  gets(buf);
  p_buf=(char *)malloc(strlen(buf)*sizeof(char));
      if ((strlen(buf)>max_leng)||(strlen(buf)==0))
            i=1;

      for(j=0;j<strlen(buf);j++)
          if(!(isalpha(buf[j])))
            i=1;
   if(i==1)
    {
        printf("\nInvalid input");
        getchar();
        strcpy(p_buf,"\0");
        return p_buf;
    }
    else
    return  strcpy(p_buf,buf);
}
char *  Get_group_name(void)
{
    char * p_buf;
  char buf[group_name_leng*2];
  int i=0,j;
  gets(buf);
   p_buf=(char *)malloc(strlen(buf)*sizeof(char));
      if ((strlen(buf)>group_name_leng)||(strlen(buf)==0))
            i=1;

      for(j=0;j<strlen(buf);j++)
          {
              if(!isalpha(buf[j]))
               i=1;
              if(buf[j]=="-")
               i=0;
          }
   if(i==1)
    {
        printf("\nInvalid input");
        getchar();
        strcpy(p_buf,"\0");
        return p_buf;
    }
    else
    return  strcpy(p_buf,buf);
}
int Get_course(void)
{
  char * p_buf;
  char buf[max_leng];
  int i=0,j;
  gets(buf);

      if ((strlen(buf)>1)||(strlen(buf)==0))
            i=1;

      for(j=0;j<strlen(buf);j++)
          {
              if(!isdigit(buf[j]))
               i=1;
          }
      if((atoi(buf)>6)||(atoi(buf)<1))
        i=1;
   if(i==1)
    {
        printf("\nInvalid input");
        getchar();
        return -1;
    }
    else
    return atoi(buf);
}
int Get_mark(void)
{
  char buf[max_leng];
  int i=0,j;
  gets(buf);
      if (strlen(buf)==0)
            i=1;

      for(j=0;j<strlen(buf);j++)
          {
              if(!isdigit(buf[j]))
               i=1;
          }
      if((atoi(buf)>100)||(atoi(buf)<0))
        i=1;
   if(i==1)
    {
        printf("\nInvalid input");
        getchar();
        return -1;
    }
    else
    return atoi(buf);
}
char * Get_auth()
{
    char * p_buf;
  char buf[max_leng*2];
  int i=0,j;
  gets(buf);
   p_buf=(char *)malloc(strlen(buf)*sizeof(char));
      if ((strlen(buf)>max_leng)||(strlen(buf)==0))
            i=1;
   if(i==1)
    {
        printf("\nInvalid input");
        getchar();
        strcpy(p_buf,"\0");
        return p_buf;
    }
    else
    return  strcpy(p_buf,buf);
}
void Show_information(STUDENT * student,LECTOR * lector)
 {

    printf("Student: %s %s \n", student->first_name,student->last_name);
    printf("Course: %d Group: %s \n", student->group_info->course,student->group_info->group_name);
    printf("Lector: %s %s Mark: %d\n",lector->first_name,lector->last_name,lector->mark);
    printf("login: %s password: %s\n\n\n",lector->auth_info->login,lector->auth_info->password);
    getchar();

 }
