//
//  Event.hpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright © 2016년 민석. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp

#ifdef _WIN32
#include <Windows.h>
#else// For Mac
#include <unistd.h> 
#endif
#include <iostream>
#include <string>

// Player 만들고
// ScreenManager에서 모든 screen 만들기

typedef struct {
	std::string name;
	int HP;
	int MP;

	std::string getName();
	int getHP();
	int getMP();
}Player;




typedef struct
Screen{
	static std::string message;
    /*
    #ifdef _WIN32
	static void MakeScreen(std::string subjectOneName, int subjectOneHP, int subjectOneMP, std::string subjectTwoName, int subejectTwoHP, int subjectTwoMP);
    #endif
    */
}Screen;


enum class Ability { STR = 0, INT, DEX };
enum class Action { Attack = 0, Defense, Skill, Rest, Dead };

typedef struct{
    static void ConsoleDelay();
}Event;

#endif /* Event_hpp */

// Ability : 능력치에 대한 Enum
// STR : Damage
// INT : Skill Damage
// DEX : Rate of hit, avoidance