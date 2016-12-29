#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef struct Inf{
    char source[40];
    char inf[1000];
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
char* setKursName(){
    char kursName[25];
    scanf("%s", kursName);
    return kursName;
}
char* setKursTheme(){
    char kursTheme[25];
    scanf("%s", kursTheme);
    return kursTheme;
}
int setKursCapacity(){
    int cap;
    int err;
    do {
		fflush(stdin);
		err = scanf("%d", &cap);
		if((cap <0) || (cap > 1000)){
             printf("Количество страниц вашей курсовой должно лежать в пределах 0 - 1000\n");
             err = 0;
        }
		else{
		err = 1;
		}
	} while ((err == 0));
    return cap;
}
char* strValidation(){

}
char* setStudName(){
     char sname[25];
     int err;
     do{
     scanf("%s", sname);
    int i;
    for(i=0;sname[i]!='\0';i++){
        if(strchr("1234567890", sname[i])){
            printf("Неверный ввод имени(присутствуют не буквенные символы). Попробуйте снова: ");
           err=0;
            break;
        }else{
        err = 1;
        }
    }}while(err==0);
    return sname;
}
char* setStudSecName(){
   char secname[25];
     int err;
     do{
     scanf("%s", secname);
    int i;
    for(i=0;secname[i]!='\0';i++){
        if(strchr("1234567890", secname[i])){
            printf("Неверный ввод имени(присутствуют не буквенные символы). Попробуйте снова: ");
           err=0;
            break;
        }else{
        err = 1;
        }
    }}while(err==0);
    return secname;
}
char* setStudGroup(){
    char gr[10];
    scanf("%s", gr);
    return gr;
}
char* setInfSource(){
    char sr[10];
    scanf("%s", sr);
    return sr;
}
char* setInf(){
    char inf[1000];
    scanf("%s", inf);
    return inf;
}

void printStruct(Kurs* a){
     printf("\n\nНазвание курсовой %s\n", a->kursName);
    printf("Тема курсовой %s\n", a->kursTheme);
    printf("Количество старниц %d \n", a->capacity);
    printf("Имя студента %s\n", a->std->name);
    printf("Фамилия студента %s\n", a->std->secName);
    printf("Група студента %s\n", a->std->group);
    printf("Источник информации %s\n", a->infrm->source);
    printf("Информация %s\n", a->infrm->inf);
}

int main()
{
     setlocale(LC_ALL, "Rus");
    Kurs* b=(Kurs *)malloc(sizeof(Kurs));
    printf("Введите название курсовой ");
    strcpy(b->kursName, setKursName());
    printf("Введите тему курсовой ");
    strcpy(b->kursTheme,setKursTheme());
    printf("Введите обьем курсовой ");
    b->capacity = setKursCapacity();
    b->std=(Stud *)malloc(sizeof(Stud));
    printf("Введите имя студента ");
    strcpy(b->std->name, setStudName());
    printf("Введите фамилию студента ");
    strcpy(b->std->secName, setStudSecName());
    printf("Введите шифр групы студента ");
    strcpy(b->std->group, setStudGroup());
    b->infrm = (Inf *)malloc(sizeof(Inf));
    printf("Введите источник информации ");
    strcpy(b->infrm->source, setInfSource());
    printf("Введите информацию ");
    strcpy(b->infrm->inf, setInf());
    printStruct(b);


    return 0;
}

