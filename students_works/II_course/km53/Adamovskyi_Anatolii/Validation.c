#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
#define max_leng 30

typedef struct authorization//Авторизація
{
	char password[max_leng];
	char login[max_leng];
} authorization;

typedef struct book//Книга
{
	char name[max_leng];
	char autor_first_name[max_leng];
  char autor_last_name[max_leng];
	int publishing_year;
}book;

typedef struct user//Користувач
{
  char first_name[max_leng];
  char last_name[max_leng];
 	int document;
 	authorization *auth;
 	book *my_book;
}user;

void color(int n)
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | n);
}

void imput_char(char ch[], const char* Message)
{
  printf("%s\n> ", Message);
  char *Number = (char *)malloc(max_leng * sizeof(char*));
  int StrLength = 0;
  int n=0;
  char PressedKey;
  int j=0;
  do
  {
    PressedKey = _getch();
    if (PressedKey == '\b')
    {
      if (StrLength>0)StrLength--;
      system("cls");
      printf("%s\n> ", Message);
      int i;
      for (i = 0; i<StrLength; i++)
        printf("%c", Number[i]);
    }
    else if ((('a' <= PressedKey&&PressedKey <= 'z') || ('A' <= PressedKey && PressedKey <= 'Z')) && StrLength<max_leng)
    {
      Number[StrLength] = PressedKey;
      StrLength++;
      printf("%c", PressedKey);
    }
    else if (PressedKey == 13 && StrLength >0) printf("\n");
  } while (PressedKey != 13 || StrLength == 0);
  for (j;j<StrLength;j++) ch[j] = Number[j];
}

void imput_int(int* n, const char *Message, int limit)
{
  printf("%s ", Message);
  char *Number = (char *)malloc(limit * sizeof(char*));
  int StrLength = 0;
  char KeyPressed;
  do
  {
    KeyPressed = _getch();
    if ('0' <= KeyPressed && KeyPressed <= '9' && StrLength <= (limit-1))
    {
      Number[StrLength] = KeyPressed;
      StrLength++;
      printf("%c", KeyPressed);
    }
    if (KeyPressed == '\b')
    {
      if (StrLength>0)StrLength--;
      system("cls");
      printf("%s\n> ", Message);
      int i;
      for (i = 0; i<StrLength; i++)
        printf("%c", Number[i]);
    }
    if (KeyPressed == 13 && StrLength>0)printf("\n");
  } while (KeyPressed != 13 || StrLength == 0);
  Number[StrLength] = '\0';
  *n = atoi(Number);
}

authorization enter_form(authorization *Auth)
{
  imput_char(&Auth->password, "Enter password: ");
  imput_char(&Auth->login, "Enter login: ");
  return *Auth;
}

book enter_book(book *Book)
{
  int i=0;
  imput_char(&Book->name,"Enter book title: ");
  imput_char(&Book->autor_first_name,"Enter first name autor: ");
  imput_char(&Book->autor_last_name,"Enter last name autor: ");
  Book->publishing_year=9999;
  while(Book->publishing_year>2016)
  {
    if (i>0) color(4);
    else color(3);
    imput_int(&Book->publishing_year,"Enter publishing year (0-2016): ",4);
    i++;
  }
  color(3);
  return *Book;
}

void print_struct(user *User)
{
    system("cls");
    printf("First name: %s\nLast name: %s\nID: %i\n\n", User->first_name, User->last_name, User->document);
    printf("Login: %s \nPassword: %s \n\n", User->auth->login,User->auth->password);
    printf("My book: %s\nAutor first name: %s\nAutor last name: %s\nPublishing year: %i \n", User->my_book->name, User->my_book->autor_first_name, User->my_book->autor_last_name,User->my_book->publishing_year);
}

void free_all(user * a, authorization *b, book *c ){
    free(a);
    free(b);
    free(c);
}

void enter_user(){
  user *User = NULL;
  authorization *Auth = NULL;
  book *Book = NULL;
  int i=0;
  User=( user*)malloc(sizeof(user));
  Auth=( authorization*)malloc(sizeof(authorization));
  Book=( book*)malloc(sizeof(book));
  imput_char(&User->first_name,"Enter first name: ");
  imput_char(&User->last_name,"Enter last name: " );
  imput_int(&User->document, "Enter your student ID: ",8);
  enter_form(Auth);
  enter_book(Book);
	User->auth = Auth;
  User->my_book = Book;
  print_struct(User);
  free_all(User,Auth,Book);
  return 0;
}

int main()
{
  color(3);
  enter_user();
	return 0;
}
