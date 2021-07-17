#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <fstream>
#include "utility.h"

void MovePlayer(int &x, int &y, int &prev_x, int &prev_y, bool autonomous, int &speed);
bool AchievedRecord(int turns, bool autonomous);
void SaveTurns(int turns);


#endif // PLAYER_H_INCLUDED
