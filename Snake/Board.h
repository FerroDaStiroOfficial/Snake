#pragma once
#define HEIGHT 20
#define LENGTH 20

class Board
{
 private:
     char k = 'w';
     int cam[HEIGHT][LENGTH];
     bool end = false;
 public:
     void drawboard();
};