//
//  Event.cpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright © 2016년 민석. All rights reserved.
//

#include "Event.hpp"

void Event::ConsoleDelay()
{

#ifdef _WIN32
	Sleep(300);
#else
	usleep(1000 * 300);
#endif

}

/*
void MakeScreen(std::string subjectOneName, int subjectOneHP, int subjectOneMP, std::string subjectTwoName, int subejectTwoHP, int subjectTwoMP)
{
    #ifdef _WIN32
	// Graphic

	system("cls");
	std::cout << "\t\t\t  " << std::endl;
	std::cout << "\t\t\t  " << std::endl;
	std::cout << "\t\t\t " << subjectOneName << "\t\t" << subjectTwoName << std::endl;
	std::cout << "\t\t\t  " << std::endl;
	std::cout << "\t\t\t " << subjectOneHP << "\t\t" << subjectTwoHP << std::endl;
	std::cout << "\t\t\t " << subjectOneMP << "\t" << subjectTwoMP << std::endl;
	std::cout << "\t\t\t  " << std::endl;
	std::cout << "\t\t\t  " << std::endl;
	std::cout << "\t\t\t  " << std::endl;
	std::cout << "\t\t\t  " << std::endl;

    #endif
	// Text Status

    
}
*/