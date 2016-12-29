#include "struct.h"
#include "struct_function.h"
#include "move.h"
#include <string.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
int getName(Student* art, char what[]  ){
  int i = 0;
  memset(art->first_name, 0, sizeof(art->first_name));
  char ch;
  int  kod_ch = 0;
  int len = 0;
  COORD coord;
  coord.X = 10;
  coord.Y = 10;
  gotoxy(coord);
  puts(what);
  coord.X=10; coord.Y=11; gotoxy(coord);
  puts("You can only use Latin letters and long no more than 20 characters");
  coord.Y =15;
  gotoxy(coord);

  memset(art->first_name,0,20);


     while (1)
     {
       ch = getch();
       kod_ch = (int) ch;
       if (kod_ch==13&&len>0&&len<=20) return 0;
       if (((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))&&(kod_ch>0)&&(len<20)) {
        printf("%c",ch);
        coord.X++;
        gotoxy(coord);
        art->first_name[len]=ch;
        ++len;
       } else
       if (kod_ch==8) {
         if (len!=0)
         {
             coord.X--;
            gotoxy(coord);
            printf("%s"," ");
            gotoxy(coord);
            --len;
         }
       } else
       {
         if (kod_ch<0) _getch();
         gotoxy(coord);
          printf("%s"," ");
               gotoxy(coord);
         printf("\a");
       }
     }
   return 0;
}
int getSirname(Student* art, char what[]  ){
 int i = 0;
  for ( i=0; i<20; ++i)
  {
    art->second_name[i]=NULL;
  }
  char ch;
  int  kod_ch = 0;
  int len = 0;
  COORD coord;
  coord.X = 10;
  coord.Y = 10;
  gotoxy(coord);
  puts(what);
  coord.X=10; coord.Y=11; gotoxy(coord);
  puts("You can only use Latin letters and long no more than 20 characters");
  coord.Y =15;
  gotoxy(coord);
     while (1)
     {
       ch = getch();
       kod_ch = (int) ch;
       if (kod_ch==13&&len>0&&len<=20) return 0;
       if (((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))&&(kod_ch>0)&&(len<20)) {
        printf("%c",ch);
        coord.X++;
        gotoxy(coord);
        art->second_name[len] = ch;
        ++len;
       } else
       if (kod_ch==8) {
         if (len!=0)
         {
             coord.X--;
            gotoxy(coord);
            printf("%s"," ");
            gotoxy(coord);
            --len;
         }
       } else
       {
         if (kod_ch<0) _getch();
         gotoxy(coord);
          printf("%s"," ");

         printf("\a");
       }
     }
   return 0;
}
int getGroup(Student* art, char what[]) {
        int i=0;
     COORD coord;
  coord.X = 10;
  coord.Y = 10;
  gotoxy(coord);
  puts(what);
  coord.Y++;
  SetColor(7,0);
   for (i=0; i<ENDGROUP; ++i) {
    coord.Y++;
   gotoxy(coord);
   if (i==0) {
    SetColor(4,0);
    puts(Group[i]);
    SetColor(7,0);
   } else
   puts(Group[i]);
   }

   char ch;
   int kod_ch;
   int now=0;
   coord.Y=12;
   gotoxy(coord);
    while(1)
    {
      ch = getch();
      kod_ch = (int)(ch);
      if (kod_ch<0)
      {
        kod_ch=getch();
        if (kod_ch==72)
        {
            if (now-1<0); else
            {
                UP_DOWN(0,now,ENDGROUP-1,0);
                --now;}
        } else
        if (kod_ch==80)
        {
             if (now+1>=ENDGROUP); else
             {
            UP_DOWN(1,now,ENDGROUP-1,0);
                 ++now;}
        }
      }  else
      if (kod_ch==13) {
            art->group = now;
            SetColor(7,0);
            return 0;
      }
    }
}
int getBank(Student* art,char what[]) {
   int i=0;
  COORD coord;
  coord.X = 10;
  coord.Y = 10;
  gotoxy(coord);
  puts(what);
  coord.Y++;
  SetColor(7,0);
   for (i=0; i<ENDBANK; ++i) {
    coord.Y++;
   gotoxy(coord);
   if (i==0) {
    SetColor(4,0);
    puts(Bank[i]);
    SetColor(7,0);
   } else
   puts(Bank[i]);
   }

   char ch;
   int kod_ch;
   int now=0;
   coord.Y=12;
   gotoxy(coord);
    while(1)
    {
      ch = getch();
      kod_ch = (int)(ch);
      if (kod_ch<0)
      {
        kod_ch=getch();
        if (kod_ch==72)
        {
            if (now-1<0); else
            {
                UP_DOWN(0,now,ENDBANK-1,1);
                --now;}
        } else
        if (kod_ch==80)
        {
             if (now+1>=ENDBANK); else
             {
            UP_DOWN(1,now,ENDBANK-1,1);
                 ++now;}
        }
      }  else
      if (kod_ch==13) {
            art->bank = now;
            SetColor(7,0);
            return 0;
      }
    }
   return 0;
}

void print (Student *user){
    COORD coord;
    coord.X = 0 ; coord.Y = 0;
    gotoxy(coord);
    printf("First name:  %s\n", user->first_name);
    printf("Second name:  %s\n", user->second_name);
    printf("Group:  %s\n", Group[user->group]);
    printf("Bank:  %s\n", Bank[user->bank]);
}
Student create(){
    Student user;
   int error=0;
     system("cls");
    error = getName(&user,"Enter your first name:" );
     system("cls");
    error = getSirname(&user,"Enter your second name:" );
    system("cls");
    error = getGroup(&user,"Choose a group from the list");
    system("cls");
    error = getBank(&user,"Choose a bank from the list");
    system("cls");

return user;
}
