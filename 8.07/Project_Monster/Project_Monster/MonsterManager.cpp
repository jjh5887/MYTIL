#include <iostream>
#include <string>
#include <fstream>
#include "MonsterManager.h"

MonsterManager::MonsterManager()
{

}
MonsterManager::MonsterManager(std::string _name, int _str, int _dex)
	:PlayerManager(_name, 100, 0, _str, _dex, 0)
{

}
MonsterManager::MonsterManager(MonsterManager& monster)
{

}
void MonsterManager::save_monster(MonsterManager* player, int n)
{
	std::ofstream fout;
	fout.open("Monster.txt");
	if (!fout)
		std::cout << "파일이 없습니다!" << std::endl;
	for (int i = 0; i < n; i++)
	{
		fout << player[n].getName() << " ";
		fout << player[n].getSTR() << " ";
		fout << player[n].getDEX() << std::endl;
	}
	fout.close();
}
int MonsterManager::load_monster(MonsterManager* player)
{
	int n = 0;
	std::ifstream fin;
	fin.open("Monster.txt");
	if (!fin)
		std::cout << "파일이 없습니다!" << std::endl;
	int c;
	std::string _name;
	int _hp, _str, _dex;
	while (c != EOF)
	{
		fin >> _name;
		fin >> _str;
		fin >> _dex;
		c = fin.get();
		player[n].setName(_name);
		player[n].setSTR(_str);
		player[n].setDEX(_dex);
		n++;
	}
	fin.close();
	return n;
}
void MonsterManager::print_monster()
{

}