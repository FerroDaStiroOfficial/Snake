#include "Snake.h"
#include <iostream>
#include <windows.h>

Snake::Snake(int x, int y)
{
	gotoxy(x, y);
	std::cout << "c";
	actpos.x = x;
	actpos.y = y;
	ser.push_front(actpos);
	nmkl = false;
}

void Snake::up()
{
	if (!nmkl) 
	{
		pos ulnm;
		ulnm.x = ser.back().x;
		ulnm.y = ser.back().y;
		ser.pop_back();
		gotoxy(ulnm.x, ulnm.y);
		std::cout << " ";
	}
	actpos.y = actpos.y - 1;
	ser.push_front(actpos);
	gotoxy(actpos.x, actpos.y);
	std::cout << "c";
	nmkl = false;
}

void Snake::down()
{
	if (!nmkl) {
		pos ulnm;
		ulnm.x = ser.back().x;
		ulnm.y = ser.back().y;
		ser.pop_back();
		gotoxy(ulnm.x, ulnm.y);
		std::cout << " ";
	}

	actpos.y = actpos.y + 1;
	ser.push_front(actpos);
	gotoxy(actpos.x, actpos.y);
	std::cout << "c";
	nmkl = false;
}

void Snake::right()
{
	if (!nmkl) {
		pos ulnm;
		ulnm.x = ser.back().x;
		ulnm.y = ser.back().y;
		ser.pop_back();
		gotoxy(ulnm.x, ulnm.y);
		std::cout << " ";
	}

	actpos.x = actpos.x + 1;
	ser.push_front(actpos);
	gotoxy(actpos.x, actpos.y);
	std::cout << "c";
	nmkl = false;
}

void Snake::left() 
{
	if (!nmkl) {
		pos ulnm;
		ulnm.x = ser.back().x;
		ulnm.y = ser.back().y;

		ser.pop_back();
		gotoxy(ulnm.x, ulnm.y);
		std::cout << " ";
	}

	actpos.x = actpos.x - 1;
	ser.push_front(actpos);
	gotoxy(actpos.x, actpos.y);
	std::cout << "c";

	nmkl = false;
}

void Snake::eat()
{
	nmkl = true;
}

int Snake::getX()
{
	return actpos.x;
}

int Snake::getY()
{
	return actpos.y;
}

bool Snake::hit()
{
	if (ser.size() != 0) 
	{
		if (ser.size() != 1) 
		{
			for (int i = 0; i < ser.size(); i++) 
			{
				if (i != 0) {
					if (ser.at(i).x == actpos.x && ser.at(i).y == actpos.y) 
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Snake::gotoxy(int x, int y) 
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

