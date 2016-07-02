#include <iostream>
#include "Saving.h"
using namespace std;
Saving::Saving()
	:Account()
{
}
Saving::Saving(char type, int id, int balance, char* name)
	:Account(type, id,balance+(balance/10),name)
{

}
Saving::~Saving(){}
void Saving::ShowAllData()
{
	cout << "°èÁÂ Type: " << GetType();
	cout << "  °èÁÂID: " << GetId();
	cout << "  ÀÜ¾×: " << GetBalance();
	cout << "  ÀÌ¸§: " << GetName() << endl;
}
int Saving::InMoney(int val)
{
	SetBalance(GetBalance()+val+val/10);
	return GetBalance();
}
bool Saving::OutMoney(int val)
{
	if (GetBalance() >= val) {
		SetBalance(GetBalance() + val);
		return true;
	}
	else {
		return false;
	}
}