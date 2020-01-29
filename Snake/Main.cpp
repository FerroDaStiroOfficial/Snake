#include <iostream>
#include <windows.h>
#include <conio.h>
#include <deque>
#include <ctime>
#include "Snake.h"
#include "Board.h"


Board b;

int main()
{
	b.drawboard();

	Snake ActSna(10, 10);
	pos fru;
	srand(time(NULL));
	fru.x = rand() % (LENGTH - 10) + 1;
	fru.y = rand() % (HEIGHT - 10) + 1;
	ActSna.gotoxy(fru.x, fru.y);
	std::cout << "F";
	
	char k = 'w';
	bool end = false;
	
	while (!end && !ActSna.hit()) 
	{ 
		
		ActSna.gotoxy(0, 0);
		if (ActSna.getX() == fru.x && ActSna.getY() == fru.y) {
			ActSna.eat();
			fru.x = rand() % (LENGTH - 10) + 1;
			fru.y = rand() % (HEIGHT - 10) + 1;
			ActSna.gotoxy(fru.x, fru.y);
			std::cout << "F";
		}
		char b;
		if (_kbhit() ) 
		{
			b = _getch();

			if (b == 'a') 
			{
				ActSna.left();
				k = b;
			}

			if (b == 'w') {
				ActSna.up();
				k = b;
			}

			if (b == 's') {
				ActSna.down();
				k = b;
			}

			if (b == 'd') {
				ActSna.right();
				k = b;
			}
		}

		else 
		{
			if (k == 'a') 
			{
				ActSna.left();
			}
			if (k == 'w') 
			{
				ActSna.up();
			}
			if (k == 's') 
			{
				ActSna.down();
			}
			if (k == 'd') 
			{
				ActSna.right();
			}
		}

		if (ActSna.getX() >= HEIGHT || ActSna.getX() <= 0 || ActSna.getY() >= LENGTH || ActSna.getY() <= 0)
		{
			end = true;
		}
		Sleep(100);
	}
}