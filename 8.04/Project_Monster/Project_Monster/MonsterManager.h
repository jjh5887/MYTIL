#pragma once
#ifndef MONSTERMANAGER_H
#define MONSTERMANAGER_H
#include "PlayerManager.hpp"
class MonsterManager : public PlayerManager
{
private:
public:
	MonsterManager();
	MonsterManager(std::string _name, int _str, int _dex);
	MonsterManager(MonsterManager& monster);
	void save_monster(MonsterManager *player, int n);
	void check_monster(MonsterManager *player);
	void print_monster();
};
#endif
