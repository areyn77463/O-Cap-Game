/** Aaron Reynolds UIN:01118087
 *
 *  Part B of this assignment is to separate the previously written program into
 *  modules using high cohesion and low coupling. The project folder contains
 *  five source code files, four header files and two text documents.
 *
 */

#include <iostream>
#include <windows.h>
#include "piece.h"
#include "player.h"
#include "grid.h"

void Setup(char grid[25][25], int pieces[10][2], bool RandPositions);
bool Menu(bool &autonomous, bool &RandPositions, bool &stationary);

using namespace std;

int main()
{
    int turns = 0;
    int score = 0;
    int speed = 1;
    int x, y, prev_x, prev_y;
    bool stationary = true;
    bool autonomous = false;
    bool RandPositions = true;
    char grid[25][25];
    int pieces[10][2];

    while((Menu(autonomous, RandPositions, stationary) == true))
    {
        x = 10;
        y = 10;
        prev_x = 10;
        prev_y = 10;
		score = 0;
        Setup(grid, pieces, RandPositions);
        UpdateGrid(pieces, grid, x, y, prev_x, prev_y, score);
        PrintGrid(grid, score, turns);
        while(score<10)
        {
            ResetPieces(grid, pieces);
            if(stationary == false)
                MovePieces(pieces);
            MovePlayer(x, y, prev_x, prev_y, autonomous, speed);
            UpdateGrid(pieces, grid, x, y, prev_x, prev_y, score);
            Sleep(500);
            PrintGrid(grid, score, turns);
            turns++;
        }

        cout<<"Won!"<<endl;

        if(AchievedRecord(turns, autonomous) == true)
            SaveTurns(turns);
        else
            cout<<"Did not break record"<<endl;


        cout<<"Press any key to continue"<<endl;
        string key;
        cin>>key;
    }

    return 0;
}

/*
This function implements the Menu functionality
It keeps track of the game modes(autonomous, RandPositions, and stationary)
which are then passed to other methods to alter functionality.
You must print the Menu, process the user's input
which sets/alters those three variables only

*/

void Setup(char grid[25][25], int pieces[10][2], bool RandPositions){
    srand(time(NULL));
    SetPieces(pieces, RandPositions);
    GridInit(grid);
    SetGrid(grid);
}

/*
This function implements the Menu functionality
It keeps track of the game modes autonomous, RandPositions, and stationary
which are then passed to other methods to alter functionality
*/
bool Menu(bool &autonomous, bool &RandPositions, bool &stationary)
{
    //This function outputs the menu to the screen
    int action;
    int pieces [10][2];
    char garbage = 'g';
    while(action!=1)
    {
    system("CLS");
    cout << "Launch                     (1)" << endl
         << "Import Positions from file (2)" << endl
         << "Random Positions           (3)" << endl
         << "Autonomous Player          (4)" << endl
         << "Human      Player          (5)" << endl
         << "Stationary Pieces          (6)" << endl
         << "Moving Pieces              (7)" << endl
         << "Exit                       (8)" << endl
         << "------------------------------" << endl
         << "Autonomous mode  :" << autonomous << endl
         << "Stationary Pieces:" << stationary << endl
         << "Random Positions :" << RandPositions << endl << endl << endl
         << "Enter Action:";
         // statements for input failure and action selection
         // switch/case for different menu actions
         newA:
         cin >> action;
         if(cin.fail())
         {
            cin.clear();
            cin >> garbage;
            cout << "Please Enter Valid Action:";
            goto newA;
         }
         else if(action<0 || action>8)
         {
            cout << "Please Enter Valid Action:";
            goto newA;
         }
         switch(action)
         {
         case 1:// manual move, stationary piece, random piece
             break;
         case 2:// piece file
             RandPositions = false;
             SetPieces(pieces, RandPositions);
             break;
         case 3:// piece random
             RandPositions = true;
             SetPieces(pieces, RandPositions);
             break;
         case 4:// player random
             autonomous=true;
             break;
         case 5:// player manual
             autonomous=false;
             break;
         case 6:// piece stationary
             stationary=true;
             break;
         case 7:// piece random
             stationary=false;
             break;
         case 8: // exit
            exit(0);
            break;
         default:
             autonomous=false;
             stationary=true;
             RandPositions=true;
             break;

         }
    }
}

