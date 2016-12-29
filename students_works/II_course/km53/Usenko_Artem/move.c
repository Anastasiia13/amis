#include <windows.h>
#include"move.h"
#include"struct.h"
void gotoxy(COORD coord) {
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void SetColor(int text, int background) {
HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(Out, (WORD)((background << 4) | text));
}
void write  (int id ,int color) {
    SetColor(id,0);
}
void UP_DOWN(int id , int now, int last , int w)
{
    if ((id == 1) && (last!=now))
    {
        COORD coord;
        coord.X=10;
        coord.Y=12+now;
        write(7,0);
        gotoxy(coord);
        if (w==0)  puts(Group[now]); else puts(Bank[now]);
        coord.Y++;
        gotoxy(coord);
        write(4,0);
        if (w==0)  puts(Group[now+1]); else puts(Bank[now+1]);
         gotoxy(coord);
    }
     if ((id == 0) && (now!=0))
    {
        COORD coord;
        coord.X=10;
        coord.Y=12+now;
        write(7,0);
        gotoxy(coord);
        if (w==0)  puts(Group[now]); else puts(Bank[now]);
        coord.Y--;
        gotoxy(coord);
        write(4,0);
         if (w==0)  puts(Group[now-1]); else puts(Bank[now-1]);
         gotoxy(coord);
    }

}
