#ifndef _WORK_H_
#define _WORK_H_

#include <stdbool.h>
#include "student.h"

struct Work{
    struct Student author;
    char title[30];
    char content[256];
};

struct works_list{
    struct Work student_work;
    struct works_list * next_work;
};

struct check_result_list{
    struct Student author;
    bool is_plagiarised;
    struct check_result_list * next_result;
};

#endif
