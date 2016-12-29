#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// food structure
struct eat_on_canteen{
	enum type_eat{
		hot_eat,  //0
		cold_eat, //1
		dessert   //2
	};
	enum type_eat type_eat; 
	char *name_eat;          
	int amount_of_portions; 
	float expense;          
}eat;
// create struct eat_on_canteen
struct eat_on_canteen *my_food =NULL;

struct eat_on_canteen *createEat(){
	my_food=(struct eat_on_canteen *)malloc(sizeof( struct eat_on_canteen)); 
 /*// audit :
	int a; 
	char *b = (char *)malloc(sizeof(char) * 80); 
	scanf("%d",&a);
	fflush(stdin);
	gets(b);
	my_food->amount_of_portions=a;
	my_food->name_eat=b;
	my_food->type_eat = hot_eat;
//*/
	
	return my_food;
}
// free memory of srtuct eat_on_canteen
struct eat_on_canteen *deleteEat(){
	free(my_food);
	return 0;
}

// struct customer
struct customer{
	enum status_of_the_person{
		enterprise, 
    	individual  
    };
	char name; 
	int year;  
	enum status_of_the_person status;
}customer;

// create struct customer
struct customer *point_customer =NULL;

struct customer *createCustomer(){
	point_customer=(struct customer *)malloc(sizeof( struct customer)); 
	
	return point_customer;
}
// free memory of srtuct customer
struct customer *deleteCustomer(){
	free(point_customer);
	return 0;
}
// struct purchase 

struct purchase {
	enum view_order { 
		electron,    
		personally  
	};
	enum payment_method{
		cash, 
		card  
	};
	enum view_order view; 
	char name_dish ;        
	enum payment_method method ; 
	float expense;           
	
}purchase ;
// create struct purchase
struct purchase *point_purchase =NULL;

struct purchase *createPurchase(){
	point_purchase=(struct purchase *)malloc(sizeof( struct purchase)); 
	
	return point_purchase;
}
// free memory of srtuct purchase
struct purchase *deletePurchase(){
	free(point_purchase);
	return 0;
}

int main(int argc, char *argv[]) {
	
/* //audit :
	my_food= createEat();
	printf("%d", my_food->amount_of_portions);
	printf("%s\n", my_food->name_eat);
	my_food=deleteEat;  */

	return 0;
}
