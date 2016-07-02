#include <iostream>
#include <string>
#include "Account.h"
using namespace std;
int Account::account_count = 0;
int Account::public_contribution = 0;
Account::Account()
{
	account_count++;
	id = 0;
	balance = 0;
	name = new char[NAME_LEN];
	public_contribution = 0;
}
Account::Account(char type, int id, int balance, char* name)
{
	account_count++;
	this->type = type;
	this->id = id;
	this->balance = balance;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name,name);
	public_contribution = 0;
}
int Account::GetId() const
{
	return id;
}
int Account::GetBalance() const
{
	return balance;
}
char* Account::GetName() const
{
	return name;
}
void Account::SetId(int val)
{
	this->id = val;
}
void Account::SetBalance(int val)
{
	balance = val;
}
void Account::SetName(char* name)
{
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Account::ShowAllData()
{
	cout << "°èÁÂ Type: " << type;
	cout << "  °èÁÂID: " << id;
	cout << "  ÀÜ¾×: " << balance;
	cout << "  ÀÌ¸§: " << name << endl;
}
int Account::InMoney(int val)
{
	balance += val;
	return balance;
}
bool Account::OutMoney(int val)
{
	if (balance >= val) {
		balance -= val;
		return true;
	}
	else {
		return false;
	}
}
void Account::set_public_contribution(int val)
{
	this->public_contribution += val;
}
Account::~Account()
{
	account_count--;
	delete[] name;
}
int Account::get_public_contribution()
{
	return public_contribution;
}
int Account::get_count()
{
	return this->account_count;
}
char Account::GetType() const
{
	return this->type;
}
int Account::get_private_Contribution()
{
	return this->private_Contribution;
}
void Account::set_private_Contribution(int val)
{
	this->private_Contribution = val;
}