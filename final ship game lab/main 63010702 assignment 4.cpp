#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<iostream>
#include<list>

char ch = ' ';
int x = 38, y = 20, m = 0, n = 0, direction = 0, k = 0, q = 0, e = 0;
int xaxis[5] = { 1,1,1,1,1 };
int yaxis[5] = { 1,1,1,1,1 };
using namespace std;
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void gotoxyammo(int m, int n)
{
	COORD k = { m, n };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), k);
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf("       ");
}
void draw_ship(int x, int y)
{
	x = max(x, 0);
	x = min(x, 80);
	y = max(y, 0);
	y = min(y, 25);
	gotoxy(x, y);
	setcolor(2, 4);
	printf(" <-0-> ");
	Sleep(100);
}
void draw_ammo(int m, int n)
{
	gotoxyammo(m, n);
	setcolor(6, 6);
	printf(":");
}
void erase_ammo(int m, int n)
{
	gotoxyammo(m, n);
	setcolor(0, 0);
	printf(" ");
	Sleep(100);
}
int main()
{
	xaxis[0] = 38 + 3;
	xaxis[1] = 38 + 3;
	xaxis[2] = 38 + 3;
	xaxis[3] = 38 + 3;
	xaxis[4] = 38 + 3;
	//case no move and shoot
	setcursor(0);
	draw_ship(x, y);
	do
	{
		if (kbhit())
		{
			ch = getch();
			//for ship
			if (ch == 'a')
			{
				direction = 1;
			}
			if (ch == 's')
			{
				direction = 2;
			}
			if (ch == 'd')
			{
				direction = 3;
			}
			// fireammo ship at y=20
			// for ammo
			if (ch == 'k')
			{
				xaxis[e] = x + 3;
				e = e + 1;
				if (e == 5)
				{
					e = 0;
				}
				yaxis[q] = 19;
				q = q + 1;
				if (q == 5)
				{
					q = 0;
				}
			}
			fflush(stdin);
		}
		if (direction == 1)// a pressed  
		{
			erase_ship(x, y);
			draw_ship(--x, y);
			if (x <= 0)
			{
				x = 0;
			}
		}
		if (direction == 2)// s pressed  
		{
			erase_ship(--x, y);
			erase_ship(++x, y);
			draw_ship(x, y);

		}
		if (direction == 3)// d pressed  
		{
			erase_ship(x, y);
			draw_ship(++x, y);
			if (x >= 80)
			{
				x = 80;
			}
		}
		// loop for build ammo

		for (k = 0; k < 5; k++) {
			if (yaxis[k] > 1)
			{
				draw_ammo(xaxis[k], yaxis[k]);
			}
		}
		// erase ammo 
		for (k = 0; k < 5; k++) {
			if (yaxis[k] > 1) {
				Sleep(100);
				erase_ammo(xaxis[k], yaxis[k]);
			}
		}
		// loop for make its move 
		for (k = 0; k < 5; k++) {
			if (yaxis[k] > 2)
				yaxis[k]--;
			else yaxis[k] = 0;
		}

		Sleep(5);



	} while (ch != 'x');
	return 0;
}