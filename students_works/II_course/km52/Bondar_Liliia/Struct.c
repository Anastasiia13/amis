#include <stdio.h>
#include <stdlib.h>

enum Subjects{
    TOCD,
    PHYSICS,
    MATH,
    MATHEMATICAL_ANALYSIS,
    ENGLISH
};

struct student {
    int number_in_list;     //Number of student in the list
    char name[20];
    char group[5];
    int visits;
    int average_mark;
};

struct elder_student {
    int number_in_list;
    char name[20];
    char group[5];
    int visits;
    float average_mark;
    int visits_list[30];        //Array of student's visits
};

struct teacher  {
    char name[20];
    enum Subjects subject;
    float marks_list[30];        //Array of student's marks on this subject
};

int main()
{
    return 0;
}
