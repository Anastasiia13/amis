struct Student* create student() {
    struct Student* student = (struct Student*)malloc(sizeof(struct Student*));
    student.first_name = get_student_first_name();
    student.last_name = get_student_last_name();
    student.course_number = get_student_course_number();
    student.group_cipher = get_student_group_chipher();
}

char* get_student_first_name() {
    return get_string("Enter your first name: ", MAX_NAME_LENGTH);
}

char* get_student_last_name() {
    return get_string("Enter your last name: ", MAX_NAME_LENGTH);
}

char* get_student_course_number() {
    return get_int("Enter your course number: ");
}

char* get_student_last_name() {
    return get_string("Enter your group cipher: ", MAX_NAME_LENGTH);
}


