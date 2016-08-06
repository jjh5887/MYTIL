#pragma once
#ifndef MONSTERMANAGER_H
#define MONSTERMANAGER_H
#include "PlayerManager.hpp"
#include <fstream>
class MonsterManager : public PlayerManager
{
private:
public:
	MonsterManager();
	MonsterManager(std::string _name, int _str, int _dex);
	MonsterManager(MonsterManager& monster);
	void save_monster(MonsterManager* monster, int n);
	int load_monster(MonsterManager* monster);
	void print_monster();
};

#endif
