//
//  Game.hpp
//  Project 1 CS32
//
//  Created by Christina Oliveira on 1/14/17.
//  Copyright © 2017 Christina Oliveira. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
class Arena;
#include <string>
class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nRats);
    ~Game();
    
    // Mutators
    void play();
    
private:
    Arena* m_arena;
    
    // Helper functions
    std::string takePlayerTurn();
};
#endif /* Game_hpp */
