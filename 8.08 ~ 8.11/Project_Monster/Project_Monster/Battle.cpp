//
//  Battle.cpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright ⓒ 2016년 민석. All rights reserved.
//

#include "Battle.hpp"

Battle::Battle(PlayerManager& one, PlayerManager& two)
{
	//    setFirst(std::move(one), std::move(two));
	setFirst(one, two);
	turns = 0;
}

bool Battle::start()
{
	bool result = battle(this->getFirstSubject(), this->getSecondSubject());

	if (!result)
	{
		std::cout << "player 1 wins" << std::endl;
		return false;
	}
	else
	{
		std::cout << "player 2 wins" << std::endl;
		return true;
	}

}

int Battle::getTurns()
{
	return turns;
}

void Battle::nextTurns()
{
	turns++;
}

bool Battle::battle(PlayerManager& one, PlayerManager& two)
{
	// 판단 - 행동 반복
	while (1)
	{
		nextTurns();
		std::cout << std::endl;

		//		Screen::MakeScreen(one.getName(), one.getHP(), one.getMP(), two.getName(), two.getHP(), two.getMP());

		std::cout << " #### TURN " << getTurns() << " #### " << std::endl;

		jugde(one, one.selectAction(two), two, two.selectAction(one));

		Event::ConsoleDelay();

		if (one.getHP() > 0 && two.getHP() > 0)
		{
			std::cout << "[" << one.getName() << "] " << one.getHP() << " ";
			std::cout << "[" << two.getName() << "] " << two.getHP() << std::endl;
			Event::ConsoleDelay();
		}

		if (one.getHP() < 1) return true;
		else if (two.getHP() < 1) return false;
	}
}

void Battle::jugde(PlayerManager& one, Action one_status, PlayerManager& two, Action two_status)
{

	// 대상의 행동
	switch (one_status) {

	case Action::Attack:

		// 나 공격
		std::cout << one.getName() << " Attack " << std::endl;
		Event::ConsoleDelay();

		switch (two_status) {
		case Action::Attack:

			// 상대 공격
			std::cout << two.getName() << " Attack " << std::endl;
			Event::ConsoleDelay();

			two.getDamage(one.hit(), one.getName());

			if (two.isDead())
			{
				one.getDamage(two.hit(), two.getName());
			}
			break;

		case Action::Defense:

			// 상대 방어
			std::cout << two.getName() << " Defense " << std::endl;

			if (two.getAvoidance())
				std::cout << two.getName() << "이(가) 회피했다!" << std::endl;
			else
				two.getDamage(one.hit(), two.getName());

			Event::ConsoleDelay();
			break;

		case Action::Skill:

			// 상대 스킬
			std::cout << two.getName() << " Skill " << std::endl;

			Event::ConsoleDelay();
			break;

		case Action::Rest:

			// 상대 휴식
			std::cout << two.getName() << " Rest " << std::endl;
			Event::ConsoleDelay();

			two.getDamage(one.hit(), one.getName());

			if (two.isDead())
			{
				two.getRest();
			}


			break;
		}
		break;

	case Action::Defense:

		// 나 방어
		std::cout << one.getName() << " Defense " << std::endl;
		Event::ConsoleDelay();
		switch (two_status) {
		case Action::Attack:

			// 상대 공격
			std::cout << two.getName() << " Attack " << std::endl;
			Event::ConsoleDelay();

			if (one.getAvoidance())
				std::cout << one.getName() << "이(가) 회피했다!" << std::endl;
			else
				one.getDamage(two.hit(), two.getName());

			break;

		case Action::Defense:

			// 상대 방어
			std::cout << two.getName() << " Defense " << std::endl;
			Event::ConsoleDelay();

			std::cout << "아무일도 일어나지않았다. " << std::endl;
			Event::ConsoleDelay();

			break;

		case Action::Skill:

			// 상대 스킬
			std::cout << two.getName() << " Skill " << std::endl;

			Event::ConsoleDelay();
			break;

		case Action::Rest:

			// 상대 휴식
			std::cout << two.getName() << " 휴식 " << std::endl;
			Event::ConsoleDelay();

			std::cout << "아무일도 일어나지않았다! " << std::endl;
			Event::ConsoleDelay();

			two.getRest();

			break;
		}
		break;

	case Action::Rest:

		// 나 휴식
		std::cout << one.getName() << " 휴식 " << std::endl;

		switch (two_status) {
		case Action::Attack:

			// 상대 공격
			std::cout << two.getName() << " Attack " << std::endl;
			Event::ConsoleDelay();

			one.getRest();
			one.getDamage(two.hit(), two.getName());

			Event::ConsoleDelay();
			break;

		case Action::Defense:

			// 상대 방어
			std::cout << two.getName() << " Defense " << std::endl;
			Event::ConsoleDelay();

			one.getRest();

			std::cout << "아무일도 일어나지않았다! " << std::endl;
			Event::ConsoleDelay();

			break;

		case Action::Skill:

			// 상대 스킬
			std::cout << two.getName() << " Skill" << std::endl;

			Event::ConsoleDelay();
			break;

		case Action::Rest:

			// 상대 휴식
			std::cout << two.getName() << " 휴식 " << std::endl;
			Event::ConsoleDelay();

			one.getRest();
			two.getRest();

			Event::ConsoleDelay();
			break;
		}
		break;

	case Action::Skill:

		// 나 스킬
		std::cout << one.getName() << " Skill " << std::endl;

		switch (two_status) {
		case Action::Attack:

			// 상대 공격
			std::cout << two.getName() << " Attack " << std::endl;
			Event::ConsoleDelay();

			Event::ConsoleDelay();
			break;

		case Action::Defense:

			// 상대 방어
			std::cout << two.getName() << " Defense " << std::endl;
			Event::ConsoleDelay();

			Event::ConsoleDelay();

			break;

		case Action::Skill:

			// 상대 스킬
			std::cout << two.getName() << " Skill " << std::endl;

			Event::ConsoleDelay();
			break;

		case Action::Rest:

			// 상대 휴식
			std::cout << two.getName() << " 휴식 " << std::endl;
			Event::ConsoleDelay();


			Event::ConsoleDelay();
			break;
		}
		break;

	default:
		break;
	}
}

PlayerManager& Battle::getFirstSubject()
{
	return this->player_1;
}
PlayerManager& Battle::getSecondSubject()
{
	return this->player_2;
}

void Battle::setFirst(PlayerManager& one, PlayerManager& two)
{
	int coin = rand() % 100;

	if (coin > 50)
	{
		player_1 = one;
		player_2 = two;
	}
	else {
		player_1 = two;
		player_2 = one;
	}
}