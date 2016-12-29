void SetColor(int text, int background) {
   
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void gotoxy(int x, int y) {
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

char user_wait(char line[], int x, int y){
	int length = strlen(line);
	int i;
	
	SetColor(12,0);
	
	gotoxy(x,y);
	printf("%s", line);
	
	while(!kbhit());
	
	gotoxy(x,y);
	for(i=0; i<length; i++)
		printf(" ");
	
	SetColor(7,0);
	
	return getch();
}
