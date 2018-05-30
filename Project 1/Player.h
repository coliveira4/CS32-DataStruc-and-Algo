//
//  Player.hpp
//  Project 1 CS32
//
//  Created by Christina Oliveira on 1/14/17.
//  Copyright © 2017 Christina Oliveira. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp
#include <string>


class Arena;

class Player
{
public:
    // Constructor
    Player(Arena* ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;
    
    // Mutators
    
    
    //I added std is this ok?
    
    
    
    std::string dropPoisonPellet();
    std::string move(int dir);
    void   setDead();
    
private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    bool   m_dead;
};


#endif /* Player_hpp */
