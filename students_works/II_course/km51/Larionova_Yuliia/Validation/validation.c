#include <conio.h>
#include <string.h>
#include <windows.h>

#define STRING_MAX_LENGTH 256

char* get_string(char* prompt, int min_length, int max_length, char* accepted_symbols) {
    printf("%s", prompt);

    char* input[STRING_MAX_LENGTH];
    int input_length = 0;
    while (true) {
        char input_symbol = _getch();
        if (input_length > max_length)||((input_symbol == '\n')&&(input_length < min_length)) {
            Beep(1480,200);
        } else if (strchr(accepted_symbols, input_symbol)) { //input symbol is in accepted symbols
            printf("%c", input_symbol);
            input[input_length] = input_symbol;
            input_length++;
        } else if (input_symbol == '\b')&&(input_length > 0) { //backspace is pressed
            printf("\b \b");
            input_length--;
            input[input_length] = '';
        } else if (input_symbol == '\n') { //enter is pressed
            printf("\n");
            return input;
        } else { //input symbol is not in accepted symbols
            Beep(1480,200);
        }
    }
}

int get_int(char* prompt, int min, int max) {
    int min_digits_count = count_digits(min);
    int max_digits_count = count_digits(max);
    input = get_string(prompt, min_digits_count, max_digits_count, DIGITS);
    int number = (int)strtol(input, (char **)NULL, 10);
    return number;
}

int count_digits(int num) {
    int n = 0;
    while(num) {
        num /= 10;
        n++;
    }
    return n;
}
