#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include <iostream>
#include <ctime>

void UpdateGrid(int pieces[10][2], char grid[25][25], int x, int y, int prev_x, int prev_y, int &score);
void PrintGrid(char grid[25][25], int score, int turns);
void GridInit(char grid[25][25]);
void SetGrid(char grid[25][25]);

#endif // GRID_H_INCLUDED
