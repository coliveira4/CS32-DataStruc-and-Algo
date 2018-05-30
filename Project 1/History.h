//
//  History.hpp
//  Project 1 CS32
//
//  Created by Christina Oliveira on 1/14/17.
//  Copyright © 2017 Christina Oliveira. All rights reserved.
//

#ifndef History_hpp
#define History_hpp
#include "globals.h"


class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
private:
    int m_nRows;
    int m_nCols;
    int m_Grid[MAXROWS][MAXCOLS];
};
#endif /* History_hpp */
