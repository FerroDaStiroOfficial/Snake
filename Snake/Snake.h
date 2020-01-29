#pragma once
#include <deque>

struct pos
{
	int x;
	int y;
};

class Snake 
{
  public:
	Snake(int x, int y);
	void up();
	void down();
	void right();
	void left();
	void eat();
	int getX();
	int getY();
	bool hit();
	void gotoxy(int x, int y);
	bool nmkl;
  private:
	pos actpos;
	std::deque<pos> ser;

};