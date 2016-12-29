#ifndef VALIDATION_H
#define VALIDATION_H

#define LETTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "1234567890"

char* get_string(char* prompt, int min_length, int max_length, char* accepted_symbols);
int get_int(char* prompt, int min, int max);

Student* create_student(Student* student);

#endif //VALIDATION_H
