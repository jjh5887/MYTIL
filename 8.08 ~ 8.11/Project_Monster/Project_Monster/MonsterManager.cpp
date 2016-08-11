#include <iostream>
#include <string>
#include <fstream>
#include "MonsterManager.h"

int MonsterManager::count = -1;

MonsterManager::MonsterManager()
	:PlayerManager()
{

}

MonsterManager::MonsterManager(std::string _name, int _str, int _dex)
	:PlayerManager(_name, 100, 0, _str, _dex, 0)
{
	count++;
}

MonsterManager::MonsterManager(MonsterManager& monster)
{

}

void MonsterManager::save_monster(MonsterManager** player, int n)
{
	std::ofstream fout;
	fout.open("Monster.txt");
	if (!fout)
		std::cout << "파일 생성 실패!" << std::endl;
	for (int i = 0; i < n; i++)
	{
		fout << std::endl << player[i]->getName() << " ";
		fout << player[i]->getSTR() << " ";
		fout << player[i]->getDEX();
	}
	fout.close();
}

void MonsterManager::load_monster(MonsterManager** player)
{
	int n = 0;
	std::ifstream fin;
	fin.open("Monster.txt");
	if (!fin)
		std::cout << "파일이 없습니다!" << std::endl;
	int c;
	std::string _name;
	int _str, _dex;
	char temp;
	while (1)
	{
		fin >> _name;
		fin >> _str;
		fin >> _dex;
		player[count] = new MonsterManager(_name, _str, _dex);
		c = fin.get();
		if (c == EOF)
			break;
	}
	fin.close();
}

int MonsterManager::getCount()
{
	return count;
}

void MonsterManager::clear_count()
{
	this->count = -1;
}

void MonsterManager::make_monster(MonsterManager** player)
{
	std::string name;
	int str, dex;
	std::cout << "이름 : ";
	std::cin >> name;
	std::cout << "STR : ";
	std::cin >> str;
	std::cout << "DEX : ";
	std::cin >> dex;
	player[(*player)->getCount()] = new MonsterManager(name, str, dex);
}

void MonsterManager::print_monster()
{

}
