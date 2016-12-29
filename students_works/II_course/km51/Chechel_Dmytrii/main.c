#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef struct Inf{
    char source[40];
    char inf[1000];
    struct Inf *nexti;
} Inf;
typedef struct Stud{
    char name[25];
    char secName[25];
    char group[5];
} Stud;
typedef struct Kurs{
    char kursName[25];
    char kursTheme[25];
    int capacity;
    struct Stud *std;
    struct Inf *infrm;
    char format[10];
} Kurs;


Kurs *ks=NULL;
Inf *in=NULL;

int setKurs() {
    Kurs *a = NULL, *b = NULL;
    char kursName[25];
    printf("%Введите название курсовой ");
    scanf("%s",kursName);
    b=(Kurs *)malloc(sizeof(Kurs));
    strcpy(b->kursName,kursName);
    printf("Введите тему курсовой ");
    scanf("%s",b->kursTheme);
    printf("Введите обьем курсовой ");
    scanf("%d",&(b->capacity));
    b->std=(Stud *)malloc(sizeof(Stud));
    printf("Введите имя студента ");
    scanf("%s",b->std->name);
    printf("Введите фамилию студента ");
    scanf("%s",b->std->secName);
    printf("Введите шифр групы студента ");
    scanf("%s",b->std->group);
    int j=0;
    while(1){
        if(b->infrm!=NULL){
         for(;b->infrm->nexti != NULL; b->infrm->nexti);
        }
        j++;
        char sour[25];
        printf("Введите источник информации ");
        scanf("%s",sour);
         if (sour[0]=='*') break;
         b->infrm=(Inf *)malloc(sizeof(Inf));
         strcpy(b->infrm->source, sour);
         printf("Введите информацию \n\n");
        scanf("%s",b->infrm->inf);
        b->infrm->nexti = NULL;
    }
    printf("Имя студента %s", b->std->name);
    if (ks==NULL) ks=b;
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    setKurs();
    return 0;
}

