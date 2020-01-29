#include "Board.h"
#include <iostream>

void Board::drawboard()
{
	int cam[HEIGHT][LENGTH];
	for (int i = 0; i < HEIGHT; i++) 
	{
		for (int j = 0; j < LENGTH; j++) 
		{
			if (i == 0 || i == HEIGHT - 1) 
			{
				std::cout << "*";
			}
			else 
			{
				if (j == 0 || j == HEIGHT - 1) 
				{
					std::cout << "*";
				}
				else 
				{
					std::cout << " ";
				}
			}
		}
		std::cout << std::endl;
	}

}

