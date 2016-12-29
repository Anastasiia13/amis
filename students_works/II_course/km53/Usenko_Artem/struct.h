#ifndef STRUCT_H
#define STRUCT_H
#define  MAXLENGTH 100
enum GROUP  {
    KM_51 , KM_52 , KM_53 , KV_51 , KV_52 , KV_53 , KP_51 , KP_52 , KP_53 , ENDGROUP};
enum BANK {
  Privat_Bank , Oshad_Bank , Ukr_Bank , ENDBANK};
 static  char *Bank[]  = {
 "Privat_Bank",
 "Oshad_Bank",
 "Ukr_Bank"};
 static  char *Group[] = {
  "KM-51",
  "KM-52",
  "KM-53",
  "KV-51",
  "KV-52",
  "KV-53",
  "KP-51",
  "KP-52",
  "KP-53"};

typedef struct Card {
    int serial_kod[MAXLENGTH] ;
    int balans;
} Card;
typedef struct Student {
  char first_name[20];
  char second_name[20];
struct  Card card  ;
  enum GROUP group;
  enum BANK  bank;
} Student;
#endif // STRUCT_H
