#pragma once
#ifndef MONSTERMANAGER_H
#define MONSTERMANAGER_H
#include "PlayerManager.hpp"
#include <fstream>
class MonsterManager : public PlayerManager
{
private:

	static int count;
public:

	MonsterManager();
	MonsterManager(std::string _name, int _str, int _dex);
	MonsterManager(MonsterManager& monster);
	MonsterManager&::MonsterManager::operator=(const MonsterManager& _subject);

	void save_monster(MonsterManager** monster, int n);
	void load_monster(MonsterManager** monster);

	int getCount();
	void clear_count();
	void print_monster();
	void make_monster(MonsterManager** player);
};
#endif
