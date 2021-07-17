#include "piece.h"

using namespace std;

//since pieces move, we clear their last position
void ResetPieces(char grid[25][25], int pieces[10][2])
{
    for(int i=0; i<10; i++)
    {
        if(pieces[i][0]!= -1 && pieces[i][1] != -1)
         grid[pieces[i][0]][pieces[i][1]] = ' ';
    }
}

void SetPieces(int pieces[10][2], bool RandPositions)
{
    if(RandPositions == true)
    {
        for(int i=0; i<10; i++)
        {
            pieces[i][0] = randCoord();
            pieces[i][1] = randCoord();
        }
    }
    else
    {
        ifstream myfile;
        myfile.open("positions.txt", ios::in);
        if(myfile)
        {
            for(int i=0; i<10; i++)
            {
                myfile>>pieces[i][0];
                myfile>>pieces[i][1];
            }
            myfile.close();
        }
        else
            cout<<"Could not open file"<<endl;
    }
}

void MovePieces(int pieces[10][2])
{
    int toss1 = -1;
    int toss2 = -1;

    for(int i=0; i<10; i++)
    {
        toss1 = coinToss();
        toss2 = coinToss();

        //move vertical
        if(toss1 == 1)
        {
            if(toss2 == 1 && pieces[i][0] > 1)
                pieces[i][0]--;
            else if(toss2 == 0 && pieces[i][0] <23)
                pieces[i][0]++;
        }
        //move horizontal
        else
        {
            if(toss2 == 1 && pieces[i][1] > 1)
                pieces[i][1]--;
             else if(toss2 == 0 && pieces[i][1] <23)
                pieces[i][1]++;
        }
    }
}
