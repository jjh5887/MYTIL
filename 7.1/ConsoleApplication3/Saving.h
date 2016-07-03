#pragma once
#ifndef SAVING_H
#define SAVING_H
#include "Account.h"
class Saving : public Account
{
public:
	Saving();
	Saving(char type, int id, int balance, char* name);
	~Saving();
	void ShowAllData();
	int InMoney(int val);
	bool OutMoney(int val);
};
#endif