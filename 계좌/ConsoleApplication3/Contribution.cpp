#include <iostream>
#include "Contribution.h"
using namespace std;
Contribution::Contribution()
	:Account()
{

}
Contribution::Contribution(char type, int id, int balance, char* name)
	:Account(type,id,balance/10*7,name)
{
	set_private_Contribution(balance / 10);
	set_public_contribution(balance / 5);
}
Contribution::~Contribution()
{}
void Contribution::ShowAllData()
{
	cout << "°èÁÂ Type: " << GetType();
	cout << "  °èÁÂID: " << GetId();
	cout << "  ÀÜ¾×: " << GetBalance();
	cout << "  ÀÌ¸§: " << GetName();
	cout << "  °³ÀÎ ±âºÎ¾×: " << get_private_Contribution() << endl;
}
int Contribution::InMoney(int val)
{
	SetBalance(GetBalance() + val/10*7);
	set_private_Contribution(val / 10);
	set_public_contribution(val / 5);
	return GetBalance();
}
bool Contribution::OutMoney(int val)
{
	if (GetBalance() >= val) {
		SetBalance(GetBalance() + val);
		return true;
	}
	else {
		return false;
	}
}