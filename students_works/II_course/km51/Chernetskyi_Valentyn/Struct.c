#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
 
 typedef struct abit_info {
     char first_name[15];
     char last_name[20];
     int age;
	 char subjects[20];
     float result_zno;
   }abit_info;
   
  typedef struct docs {
     char type[15];
     struct abit_info *ABIT;
   }docs;
 
   typedef struct task_info {
     char name[20];
	 char type[20];
	 int quantity_exersises;
     struct subjects *SUBJECTS;
   }task_info;
   
   typedef struct vnz_info {
     char name[20];
     char adress[20];
	 char phone_number[9];
     float result;
   }vnz_info;
 
 int main()
 {
     abit_info *abit1 = NULL;
     abit1 = (abit_info *) malloc(sizeof(abit_info));
 
     free(abit1);
	 
	 docs_info *doc1 = NULL;
     doc1 = (docs_info *) malloc(sizeof(docs_info));
 
     free(doc1);
 
     task_info *task1 = NULL;
     task1 = (task_info *) malloc(sizeof(task_info));
 
     free(task1);
 
     vnz_info *vnz1 = NULL;
     vnz1 = (vnz_info *) malloc(sizeof(vnz_info));
 
     free(vnz1);
 
     return 0;
 }