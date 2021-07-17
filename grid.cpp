#include "grid.h"

using namespace std;

//initializes the grid 2D array
void GridInit(char grid[25][25])
{
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<25; j++)
            grid[i][j]=' ';
    }
}

//sets the lines for the borders in the grid
void SetGrid(char grid[25][25])
{
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<25; j++)
        {
            if(i==0 || i==24)
                grid[i][j]='-';//-
            else
            {
                if(j==0 || j==24)
                    grid[i][j]='|';
                else
                    cout<<' ';
            }
        }
    }
}

/*
Checks to see if a coordinate in a single axis
is between two other coordinates
*/
bool InRange(int x, int y, int z)
{
    if((x>= z && y<= z) || x<=z && z<=y)
        return true;
    else return false;
};

//Checks if a capture is observed by the player on a piece
//since we can jump over a piece when speed > 1, we can't
//just check if they player and piece fall on the same square
bool DetectCapture(int x, int y, int p_x, int p_y, int dx, int dy){

     if(InRange(x, p_x, dx) == true && y == dy && p_y == y)
        return true;
    else if(InRange(y, p_y, dy) == true && x == dx && p_x == x)
        return true;
    else
        return false;
};

/*
    Updates the grid with the player's and pieces' position
    checks to see if a capture is made so that the piece can
    be deleted
    prev_x and y is the player's position at the last turn
    deletes the 'X' graphic from the player's last position
    updates the score.
    Looks at the grid and checks if a capture has been made
    and updates the graphics accordingly
*/
void UpdateGrid(int pieces[10][2], char grid[25][25], int x, int y, int prev_x, int prev_y, int &score){

    grid[prev_x][prev_y] = ' ';
    char dir = ' ';
    for(int i=0; i<10; i++){
        //capture
        if(DetectCapture(x, y, prev_x, prev_y, pieces[i][0], pieces[i][1]) == true){
            pieces[i][0] = -1;
            pieces[i][1] = -1;
            score++;
        }
        else if(pieces[i][0] != -1 && pieces[i][1] != -1){
            grid[pieces[i][0]][pieces[i][1]]='o';
        }
    }
    if(x != 0 && x!= 24 && y!=0 && y!=24)
        grid[x][y]='X';
}

void PrintGrid(char grid[25][25], int score, int turns){
    system("CLS");
    cout<<"Move with a,d,s,w. Any other key to not move"<<endl;
    cout<<"x to increase speed"<<endl;
    cout<<"z to decrease speed"<<endl;
    //make sure grid edges remain intact
     for(int i=0; i<25; i++)
    {
        for(int j=0; j<25; j++)
        {
            if(i==0 || i==24)
                grid[i][j]='-';//-
            else{
                if(j==0 || j==24)
                    grid[i][j]='|';
            }
        }
    }

    for(int i=0; i<25; i++)
    {
        for(int j=0; j<25; j++)
            cout<<grid[i][j];
        cout<<endl;
    }
    cout<<"Score:"<<score<<endl;
    cout<<"Turns:"<<turns<<endl;
}
