#pragma once
#ifndef CONTRIBUTION_H
#define CONTRIBUTION_H
#include "Account.h"
class Contribution : public Account
{
public:
	Contribution();
	Contribution(char type, int id, int balance, char* name);
	~Contribution();
	void ShowAllData();
	int InMoney(int val);
	bool OutMoney(int val);
};
#endif