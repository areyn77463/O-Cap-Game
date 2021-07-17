#include "player.h"

using namespace std;

/*
randomly chooses where the player moves
uses random number generator to determine where to go
updates the x and y coordinates. You do not need to implement
your own random number generator. Instead, use the coinTossn function
*/
void AutonomousPlayerMove(int &x, int &y)
{
    //using coinToss to generate 2 random int
    int toss1 = coinToss();
    int toss2 = coinToss();
    //if/else statements to automatically move player by 1 space per turn
    if(toss1 == 1)
    {
        if(toss2 == 1 && y > 1)
            y--;
        else if(toss2 == 0 && y <23)
                y++;
    }
    else
    {
        if(toss2 == 1 && x > 1)
            x--;
        else if(toss2 == 0 && x <23)
            x++;
    }
};

/*
This function checks if a player has moved
to the grid's edges, 0 or 24 and transports them
to the opposite side if that is the case, by updating
the coordinates x and y*/
void GridEdgeTransport(int &x, int &y){
    // if x or y exceeds the grid on one side
    // x or y will appear in same row or column
    // on the other side
    if(x>24)
        x=1;
    if(x<0)
        x=23;
    if(y>24)
        y=1;
    if(y<0)
        y=23;
};

void ManualMove(int &x, int &y, int &speed){
    char direction;
    cout<<"Enter Move:";
    cin>>direction;

    if(direction == 'a')
        y-=speed;
    else if(direction == 'w')
        x-=speed;
    else if(direction == 'd')
        y+=speed;
    else if(direction == 's')
        x+=speed;
    else if(direction == 'z')
    {
        if(speed>=2)
            speed--;
    }
    else if(direction == 'x')
        {
        if(speed<5)
            speed++;
    }
};

void MovePlayer(int &x, int &y, int &prev_x, int &prev_y, bool autonomous, int &speed)
{
    //vertical
    prev_x = x;
    prev_y = y;

    if(autonomous == false)
		ManualMove(x, y, speed);

    else
        AutonomousPlayerMove(x, y);

    GridEdgeTransport(x, y);
}

/*
This function reads the best
score from a file, and checks
whether the player has finished the game
in fewer turns than indicated on file.
It must return true or false based on whether
a record was achieved or not. If autonomous mode is enabled
then the record doesn't count and thus not saved in the file
*/
bool AchievedRecord(int turns, bool autonomous)
{
    // This will retrieve alias and highscore from a text document
    // and check to see if player has beaten high score to return bool
    std::string alias;
    int high_score;

    ifstream input("leaderboard.txt");
    input >> alias >> high_score;
    input.close();
    if(turns<high_score && autonomous==false)
        return true;
    else return false;
}

/*
This function is activated when a best score has been beaten
 it promptes the user for an alias
and prints the alias along with turns on the 'leaderboard.txt' file
*/
void SaveTurns(int turns)
{
    // This function will prompt the user to enter an alias to save
    // to the leaderboard upon breaking the highscore
    std::string alias;
    cout << "You broke the record!" << endl
         << "Please enter an alias:";
    cin >> alias;
    ofstream outfile("leaderboard.txt");
    outfile << alias << " " << turns;
    outfile.close();
}

