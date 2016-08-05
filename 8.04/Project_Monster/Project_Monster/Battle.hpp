//
//  Battle.hpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright © 2016년 민석. All rights reserved.
//

#ifndef Battle_hpp
#define Battle_hpp
#include <iostream>
#include <string>
#include "PlayerManager.hpp"
#include "Event.hpp"

class Battle{
    PlayerManager player_1;
    PlayerManager player_2;
    int turns;

public:
    Battle(PlayerManager& one, PlayerManager& two);
    
    void start();
    void setFirst(PlayerManager& one, PlayerManager& two);
    bool battle(PlayerManager& one, PlayerManager& two);
    void jugde(PlayerManager& one, Action one_status, PlayerManager& two, Action two_status);
    
    int getTurns();
    void nextTurns();
    
    PlayerManager& getFirstSubject();
    PlayerManager& getSecondSubject();
    
    
    
};

#endif /* Battle_hpp */
