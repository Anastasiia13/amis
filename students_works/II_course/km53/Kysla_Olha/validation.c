#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
// Valid +float
 float getFloat() {
    char *str = (char *)malloc(sizeof(char) * 80); 
    int valid=0;
    while(valid==0){
    	valid=1;
		int counter = 0 ;
    	gets(str);
    	int i;
    	if (strlen(str)==0|| strlen(str)>=7){
    		valid=0;
		}
   		 for( i=0 ; i<strlen(str) ; i++) {
          	 if(str[i]>='0' && str[i]<='9') {            
          	 }   
          	 else {
               	if(str[i] == '.') {
                 	 counter++ ;
               	} 
             	 else  valid=0 ; 
              	if(counter > 1) valid=0 ;     
           	}
    	 }
    	 
    	if(valid==0){
		  	printf("ERROR! . Enter again.\n");
		  	printf("Type must be an float namber, greater than zero, maximum number of symbols< 7.\n");
		}
    }
    float b;
	b = atof(str);
	free(str);
	return b ;
  
}

// Valid   +int
int getInt() {
    char *str = (char *)malloc(sizeof(char) * 80); 
    int valid=0; 
    int i;
    while(valid==0){
    	valid=1;
    	gets(str);
    	if(strlen(str) == 0){
		 
		 	valid=0;
	    }
	    if(strlen(str)>5){
	    	valid=0;
		}
		for( i=0 ; i<strlen(str) ; i++) {
           	if(!(str[i]>='0' && str[i]<='9'))
		    {
				valid=0;    
           	}   
       }
       if(valid==0) {
	   		printf("ERROR!  Enter again.\n");
	  		printf("Type must be an integer namber, greater than zero, maximum number of symbols< 5.\n");
	   }
      
    }
    int a;
    a=atoi(str);
    free(str);
	return a;
}  

// Valid Char
 char* getChar() {
	int i,	valid=0;
	char *str = (char *)malloc(sizeof(char)*80); 
    while(valid==0){
    	valid=1;
		gets(str);
        if(strlen(str)==0||strlen(str)>=20){
        	valid=0;
		}
		for( i=0 ; i<strlen(str) ; i++) {
			if((str[i]>='A' && str[i]<='Z')||(str[i]>='a' && str[i]<='z')){
			
			}
			else   	valid=0;
		}
		if(valid==0){
	 		printf("ERROR! Enter again.\n");
	 		printf("Type must be char ,English words, maximum number of symbols< 20 .\n");
	 	}
	}
	return str;	
}

// Struct Eat
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

static const char *EAT[] = {
    "hot_eat", "cold_eat", "dessert"
};

// Create function struct eat_on_canteen
struct eat_on_canteen *my_food =NULL;
struct eat_on_canteen *createEat(){
	my_food=(struct eat_on_canteen *)malloc(sizeof( struct eat_on_canteen)); 
	printf("Enter type_eat (enter number):\n");
	printf("0 -hot_eat;\n");
	printf("1 -cold_eat;\n");
	printf("2 -dessert.\n");
	int number;
	while (1){
		number= getInt();
		
		if (number < 0 || number>2) {
			printf("ERROR. Select the displayed number\n");
			continue;
		} 
		
		my_food->type_eat = number; 
		break;
		
	}
	printf("Enter name_eat (type Char):\n");
    my_food->name_eat = getChar();
    printf("Enter amount_of_portions(type integer):\n");
	my_food->amount_of_portions = getInt();
	printf("Enter expense (type float):\n");
	my_food->expense = getFloat();
	
	return my_food;
}

// free memory of srtuct eat_on_canteen
void deleteEat(){
	free(my_food->name_eat);
	free(my_food);
}

// Function print struct eat_on_canteen
void print_createEat(){
    
    printf("type_eat: %s\n", EAT[my_food->type_eat]);
    
    printf("name_eat: ");
	printf("%s\n", my_food->name_eat);
	printf("amount_of_portions: ");
	printf("%d\n", my_food->amount_of_portions);
	printf("expense: ");
	printf("%.2f\n\n", my_food->expense);
}

// struct customer
struct customer{
	enum status_of_the_person{
		enterprise, 
    	individual  
    };
	char *name; 
	int  year;  
	enum status_of_the_person status; 
}customer;

static const char *CUS[] = {
    "enterprise", "individual"
};

// create struct customer
struct customer *point_customer =NULL;
struct customer *createCustomer(){
	point_customer=(struct customer *)malloc(sizeof( struct customer)); 
	printf("Enter status_of_the_person (enter number):\n");
	printf("0 -enterprise;\n");
	printf("1 -individual;\n");
	int number;
	while (1){
		number= getInt();
		if (number < 0 || number>1) {
			printf("ERROR.  Select the displayed number\n");
			continue;
		} 
		point_customer->status = number; 
		break;
	}
	printf("Enter name (type Char):\n");
    point_customer->name = getChar();
    
    printf("Enter year(type integer):\n");
    point_customer->year = getInt();
    
	return point_customer;
}
// print struct Customer
void print_createCustomer(){
    
    printf("status_of_the_person: %s\n", CUS[point_customer->status]);
    
    printf("name: ");
	printf("%s\n", point_customer->name);
	
	printf("year: ");
	printf("%d\n\n", point_customer->year);

}

// free memory of srtuct customer
void deleteCustomer(){
	free(point_customer->name);
	free(point_customer);

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
	char *name_dish ;       
	enum payment_method method ; 
	float expense;             
	
}purchase ;

static const char *order[] = {
    "electron", "personally "
};

static const char *p_met[] = {
    "cash", "card"
};

// create struct purchase
struct purchase *point_purchase =NULL;
struct purchase *createPurchase(){
	point_purchase=(struct purchase *)malloc(sizeof( struct purchase)); 
	printf("Enter view_order (enter number):\n");
	printf("0 -electron;\n");
	printf("1 -personally;\n");
	int number;
	while (1){
		number= getInt();
		if (number < 0 || number>1) {
			printf("ERROR. Select the displayed number\n");
			continue;
		} 
		point_purchase->view = number; 
		break;
	}
	printf("Enter payment_method (enter number):\n");
	printf("0 -cash;\n");
	printf("1 -card;\n");
	while (1){
		number= getInt();
		if (number < 0 || number>1) {
			printf("ERROR. Select the displayed number\n");
			continue;
		} 
		point_purchase->method = number; 
		break;
	}
	
	printf("Enter name_dish (type Char):\n");
    point_purchase->name_dish = getChar();
    
    printf("Enter expense(type integer):\n");
    point_purchase->expense = getFloat();
     
	return point_purchase;
}
// print struct Purchase
void print_createPurchase(){
    
    printf("view_order: %s\n", order[point_purchase->view]);
    printf("payment_method: %s\n", p_met[point_purchase->method]);
    
    printf("name_dish: ");
	printf("%s\n", point_purchase->name_dish);
	
	printf("year: ");
	printf("%.2f\n\n", point_purchase->expense);

}
// free memory of srtuct purchase
struct purchase *deletePurchase(){
	free(point_purchase->name_dish);
	free(point_purchase);
	return 0;
}
////// main/////
int main(int argc, char *argv[]) {
	
	my_food= createEat();
	point_customer=createCustomer();
	point_purchase=createPurchase();
	
	system("cls");
	
	print_createEat();
    print_createCustomer();
    print_createPurchase();
    
	deleteEat(); 
	deleteCustomer();
	deletePurchase();
	
	return 0;
}
