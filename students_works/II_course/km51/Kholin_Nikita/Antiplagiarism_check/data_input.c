char* get_string(char* prompt, int max_length){
    printf(prompt);
    char result[max_length]
    scanf("%s", result);
    return result;
}

char* get_int(char* prompt){
    printf(prompt);
    int result;
    scanf("%d", result);
    return result;
}
