//
//  PlayerManager.cpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright © 2016년 민석. All rights reserved.
//

// 변경사항 : 인자없는생성자에 기본체력(100), 기본마나(0), 기본지능(0)으로 설정
//            이름, str, dex 설정기능 추가
#include "PlayerManager.hpp"

PlayerManager::PlayerManager()
{
	this->HP = 100;
	this->MP = 0;
	this->INT = 0;
	this->name = "NONAME";
}

PlayerManager::PlayerManager(const CustomPlayer& _man)
{
	this->name = _man.getName();
	this->HP = _man.getHP();
	this->MP = _man.getMP();
	this->STR = _man.getSTR();
	this->DEX = _man.getDEX();
	this->INT = _man.getINT();
}


PlayerManager::PlayerManager(std::string _name, int _HP, int _MP, int _STR, int _DEX, int _INT)
{
	int sumState = _STR + _DEX + _INT;
	if (sumState > 20)
	{
		std::cout << "경고!! " << _name << "의 스탯이 비정상적입니다. " << std::endl;
	}
	else if (sumState < 20)
	{
		std::cout << "경고!! " << _name << "의 스텟을 모두 분배하지 않았습니다. " << std::endl;
	}

	this->name = _name;
	this->HP = _HP;
	this->MP = _MP;
	this->STR = _STR;
	this->DEX = _DEX;
	this->INT = _INT;
}

std::string PlayerManager::getName() const
{
	return this->name;
}

int PlayerManager::getHP() const
{
	return HP;
}

int PlayerManager::getMP() const
{
	return MP;
}

int PlayerManager::getSTR() const
{
	return STR;
}

int PlayerManager::getDEX() const
{
	return DEX;
}

int PlayerManager::getINT() const
{
	return INT;
}

PlayerManager& PlayerManager::operator=(const PlayerManager& _subject)
{
	name = _subject.getName();
	HP = _subject.getHP();
	STR = _subject.getSTR();
	DEX = _subject.getDEX();
	INT = _subject.getINT();

	return *this;
}

int PlayerManager::hit() const
{
	const int additional = rand() % STR + DEX;

	return ((double)(STR*0.7)*(double)(DEX*0.3)) * 2 + additional;
}

bool PlayerManager::isDead() const
{
	if (this->getHP() > 0) return false;
	else return true;
}

void PlayerManager::getDamage(const int _demage, const std::string opponent_name)
{
	//	Screen::message += opponent_name + "가 " + _demage + " 데미지를 가했다!\n";
	std::cout << opponent_name << " 가 " << _demage << " 데미지를 가했다! " << std::endl;
	HP -= _demage;
	Event::ConsoleDelay();
}

void PlayerManager::getRest()
{
	if (HP == 100)
	{
		std::cout << this->getName() << "는(은) 휴식을 취했지만 아무일도 없었다." << std::endl;
	}
	else if (HP > 95)
	{
		std::cout << this->getName() << "는(은) " << 100 - HP << "HP를 회복했다!" << std::endl;
		HP = 100;
	}
	else
	{
		HP += 5;
		std::cout << this->getName() << "는(은) 5HP를 회복했다!" << std::endl;
	}
	Event::ConsoleDelay();
}

bool PlayerManager::getAvoidance() const
{
	const int rate = 20 + 5 * DEX;

	if ((rand() * 100) <= rate)
	{
		return true;
	}
	return false;
}

void PlayerManager::getInfo() const
{
	std::cout
		<< " Name : " << name
		<< " \tHP : " << HP
		<< " MP : " << MP
		<< " STR : " << STR
		<< " DEX : " << DEX
		<< " INT : " << INT << std::endl;
}

Action PlayerManager::selectAction(const PlayerManager& opponent)
{
	// 플레이어 기본 패턴
	int randSelector = rand() % 3;

	switch (randSelector) {
	case 0:
		return Action::Attack;
		break;

	case 1:
		return Action::Defense;
		break;

	case 2:
		//            return Action::Skill;
		return Action::Rest;
		break;

	default:
		//            return Action::Rest;
		return Action::Skill;
		break;
	}
}

CustomPlayer::CustomPlayer(std::string _name, int _HP, int _MP, int _STR, int _DEX, int _INT)
	:PlayerManager(_name, _HP, _MP, _STR, _DEX, _INT)
{ }

Action CustomPlayer::selectAction(const PlayerManager& opponent)
{
	// 커스텀 플레이 패턴
	// Input your pattern

	return Action::Attack;
}