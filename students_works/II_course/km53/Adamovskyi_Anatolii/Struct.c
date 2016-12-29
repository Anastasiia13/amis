#include <stdio.h>
#include <stdlib.h>

#define max_leng 30

typedef struct authorization//Авторизація
{
	char password[max_leng];
	char login[max_leng];
} authorization;

typedef struct book//Книга
{
	char name[max_leng];
	char autor[max_leng];
	int publishing_year;
}book;

typedef struct user//Користувач
{
	char first_name[max_leng];
    char last_name[max_leng];
   	char document[max_leng];
   	authorization *auth;
   	book *my_book;
}user;

int main()
{
	user *User = NULL;
	authorization *Auth = NULL;
	book *Book = NULL;

	User=( user*)malloc(sizeof(user));
	Book=( book*)malloc(sizeof(book));
	Auth=( authorization*)malloc(sizeof(authorization));

	strcpy(User->first_name,"Anatoliy");
   	strcpy(User->last_name,"Adamovskiy");
   	strcpy(User->document,"XX-00-00-00");

   	User->auth = Auth;

   	strcpy(Auth->password,"password");
   	strcpy(Auth->login,"login");

   	User->my_book = Book;

   	strcpy(Book->name,"Visual C++");
   	strcpy(Book->autor,"Ivor Horton");
   	Book->publishing_year=2010;

   	printf("User: %s %s %s \n\n", User->first_name, User->last_name, User->document);
    printf("Login: %s \nPassword: %s \n\n", User->auth->login,User->auth->password);
    printf("My book: %s %s %i \n ", User->my_book->name, User->my_book->autor, User->my_book->publishing_year);

    free(User);
    free(Auth);
    free(Book);

	return 0;
}
