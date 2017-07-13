//
//  History.cpp
//  Project 1 CS32
//
//  Created by Christina Oliveira on 1/14/17.
//  Copyright © 2017 Christina Oliveira. All rights reserved.
//

#include "History.h"
#include "globals.h"
//#include "Arena.h"
#include <iostream>
using namespace std;


//constructor to set all to zero, player has been nowhere
History::History(int nRows, int nCols)
:m_nRows(nRows),m_nCols(nCols)
{
    for(int r=1; r<=m_nRows; r++)
    {
        for(int c=1; c<=m_nCols; c++)
        {
            m_Grid[r-1][c-1] = 0;
        }
    }
}

//called to add one to history at that grid point, check to see if in bounds first

bool History::record(int r, int c)
{
    if(r>m_nRows || c>m_nCols)
        return false;
    
    m_Grid[r-1][c-1]++;
    return true;
}

//TODO: this isnt diplaying anything
void History::display() const
{
        clearScreen();
    
    char historyGrid[MAXROWS][MAXCOLS];
    
        for (int r = 1; r <= m_nRows; r++)
        {
            for (int c = 1; c <= m_nCols; c++)
            {
                int numPoisonedHere = m_Grid[r-1][c-1];
                if(numPoisonedHere == 0)
                    historyGrid[r-1][c-1] = '.';
                else if(numPoisonedHere >= 26)
                    historyGrid[r-1][c-1] = 'Z';
                else
                    historyGrid[r-1][c-1] = 64 + numPoisonedHere;
            }
        }
    
    for (int r = 1; r <= m_nRows; r++)
    {
        for (int c = 1; c <= m_nCols; c++)
        {
            cout<<historyGrid[r-1][c-1];
        }
        cout<<endl;
    }

     cout<<endl;
    
    
}




