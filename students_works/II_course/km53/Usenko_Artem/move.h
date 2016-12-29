#ifndef MOVE_H
#define MOVE_H
#include <windows.h>
void gotoxy(COORD coord);
void SetColor(int text, int background);
void UP_DOWN(int id , int now, int last,int w);
void write(int id, int color);
#endif
