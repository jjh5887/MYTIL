#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
const int NAME_LEN = 100;
class Account
{
private:
	char type;
	int id;
	int balance;
	char *name;
	static int account_count;
	static int public_contribution;
	int private_Contribution;
public:
	Account();
	Account(char type, int id, int balance, char* name);
	virtual ~Account();
	virtual void ShowAllData();
	virtual int InMoney(int val);
	virtual bool OutMoney(int val);
	char GetType() const;
	int GetId()const;
	int GetBalance() const;
	char* GetName() const;
	void SetId(int val);
	void SetBalance(int val);
	void SetName(char* name);
	void set_public_contribution(int val);
	int get_public_contribution();
	int get_count();
	int get_private_Contribution();
	void set_private_Contribution(int val);
};
#endif