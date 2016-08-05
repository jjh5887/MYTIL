#include <iostream>
#include <string>
#include <fstream>
#include "MonsterManager.h"

MonsterManager::MonsterManager()
{

}
MonsterManager::MonsterManager(std::string _name, int _str, int _dex) {

}
MonsterManager::MonsterManager(MonsterManager& monster)
{

}
void MonsterManager::save_monster(MonsterManager *player, int n)
{
	std::ofstream fout;
	fout.open("Monster.txt");
	if (!fout)
		std::cout << "파일이 없습니다!" << std::endl;
	for (int i = 0; i < n; i++)
	{
		fout << player[i].getName() << " ";
		fout << player[i].getSTR() << " ";
		fout << player[i].getDEX() << std::endl;
	}
	fout.close();
}
void MonsterManager::check_monster(MonsterManager *player)
{
	int n = 0;
	std::ifstream fin;
	fin.open("Monster.txt");
	if (!fin)
		std::cout << "파일이 없습니다!" << std::endl;
	int c;
	std::string name;
	int hp, str, dex;
	while (c != EOF)
	{
		fin >> name;
		fin >> str;
		fin >> dex;
		c = fin.get();
		player[n].name = name;
		player[n].STR = str;
		player[n].DEX = dex;
		n++;
	}
	fin.close();
}
void MonsterManager::print_monster()
{

}