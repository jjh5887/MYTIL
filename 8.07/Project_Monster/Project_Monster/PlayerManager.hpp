//
//  PlayerManager.hpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright © 2016년 민석. All rights reserved.
//

#ifndef PlayerManager_hpp
#define PlayerManager_hpp

#include <iostream>
#include <string>
#include "Event.hpp"

class CustomPlayer;
class PlayerManager
{
private:
    std::string name;
    int HP;
    int MP;
    int STR;
    int DEX;
    int INT;
    
public:
    PlayerManager();
    PlayerManager(std::string _name, int _HP, int _MP, int _STR, int _DEX, int _INT);
    PlayerManager(const CustomPlayer& _man);
    
    PlayerManager& operator=(const PlayerManager& _subject);
    
    std::string getName() const;
    int getHP() const;
    int getMP() const;
    int getSTR() const;
    int getDEX() const;
    int getINT() const;

	void setName(std::string _name);
	void setSTR(int _str);
	void setDEX(int _dex);

    
    int hit() const;
	bool isDead() const;

    void getDamage(int _damage, std::string opponent_name);
    void getRest();
    bool getAvoidance() const;
    void getInfo() const;
    
    virtual Action selectAction(const PlayerManager& opponent);
};

class CustomPlayer : public PlayerManager
{
public:
    CustomPlayer(std::string _name, int _HP, int _MP, int _STR, int _DEX, int _INT);
    
    Action selectAction(const PlayerManager& opponent);
};

#endif /* PlayerManager_hpp */
