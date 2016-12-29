#include <string.h>

Student* create_student() {
    Student* student = (Student*)malloc(sizeof(Student));
    student->first_name = get_student_first_name();
    student->last_name = get_student_last_name();
    student->university_name = get_student_university_name();
    student->course = get_student_course();
    student->faculty_name = get_student_faculty_name();
    student->group = get_student_group();
}

char* get_student_first_name() {
    return get_string("Enter first name: ", 3, MAX_STUDENT_NAME_LENGTH, LETTERS);
}

char* get_student_last_name() {
    return get_string("Enter last name: ", 3, MAX_STUDENT_NAME_LENGTH, LETTERS);
}

char* get_student_university_name() {
    return get_string("Enter university name: ", 3, MAX_UNIVERSITY_NAME_LENGTH, LETTERS);
}

int get_student_course_name() { 
    return get_int("Enter course: ", 1, 6);
}

char* get_student_faculty_name() {
    return get_string("Enter faculty name: ", 2, MAX_FACULTY_NAME_LENGTH, LETTERS);
}

char* get_student_group_name() {
    return get_string("Enter group name: ", 2, MAX_GROUP_NAME_LENGTH, strcat(LETTERS, DIGITS);
}
