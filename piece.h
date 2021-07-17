#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include "utility.h"
#include <iostream>
#include <fstream>

void ResetPieces(char grid[25][25], int pieces[10][2]);
void SetPieces(int pieces[10][2], bool RandPositions);
void MovePieces(int pieces[10][2]);

#endif // PIECE_H_INCLUDED
