#include <iostream>
#include <fstream>
using namespace std;
#include "Account.h"
#include "Contribution.h"
#include "Saving.h"
#include "exception.h"
#define MAX 10
void PrintMenu();
void make_Gaccount(Account** ac, int& m);
void make_Saccount(Account** ac, int& m);
void make_Caccount(Account** ac, int& m);
void deposit(Account** ac, int& m);
void withdraw(Account** ac, int& m);
void delete_account(Account** ac, int& m);
void show_all(Account** ac, int m);
void del_mom(Account** ac, int m);
void File_Out(Account** ac, int m);
void File_In(Account** ac, int& m);
int main()
{
	int i,i2,num=0;
	Account* account[MAX];
	try
	{
		File_In(account, num);
	}
	catch (MyException& ex)
	{
		cout << "예외에 대한 설명 : " << ex.description << endl;
	}
	while (true)
	{
		PrintMenu();
		cout << "메뉴를 선택하세요 : ";
		cin >> i;
		fflush(stdin);
		switch (i)
		{
		case 1:
			if (num > 9)
			{
				cout << "계좌를 추가로 개설하실 수 없습니다!" << endl;
				break;
			}
			cout << "계좌 종류 선택(1.일반계좌 2.저축계좌 3.기부계좌): ";
			cin >> i2;
			switch (i2)
			{
			case 1:
				make_Gaccount(account, num);
				break;
			case 2:
				make_Saccount(account, num);
				break;
			case 3:
				make_Caccount(account, num);
				break;
			default:
				cout << "잘못된 입력.." << endl;
				break;
			}
			break;
		case 2:
			delete_account(account, num);
			break;
		case 3:
			deposit(account, num);
			break;
		case 4:
			withdraw(account, num);
			break;
		case 5:
			cout << "현재 계좌의 수는 : " << account[num]->get_count() << endl;
			break;
		case 6:
			cout << "현재의 공동 기부액: " << account[num]->get_public_contribution() << endl;
			break;
		case 7:
			show_all(account, num);
			break;
		case 8:
			File_Out(account, num);
			del_mom(account, num);
			exit(0);
			break;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
}
void PrintMenu()
{
	cout << "-----------MENU-----------" << endl;
	cout << "1(계좌 개설)" << endl;
	cout << "2(계좌 해지)" << endl;
	cout << "3(입금)" << endl;
	cout << "4(출금)" << endl;
	cout << "5(계좌 갯수 조회)" << endl;
	cout << "6(공동 기부금 조회)" << endl;
	cout << "7(전체 계좌 정보 조회)" << endl;
	cout << "8(프로그램 종료)" << endl;
}
void make_Gaccount(Account** ac, int& m)
{
	int id;
	int bal;
	char name[NAME_LEN];
	cout << "계좌개설을 위한 입력(계좌id  잔액  이름):";
	cin >> id >> bal >> name;
	ac[m] = new Account('G',id, bal, name);
	m++;
}
void make_Saccount(Account** ac, int& m)
{
	int id;
	int bal;
	char name[NAME_LEN];
	cout << "계좌개설을 위한 입력(계좌id  잔액  이름):";
	cin >> id >> bal >> name;
	ac[m] = new Saving('S',id, bal, name);
	m++;
}
void make_Caccount(Account** ac, int& m)
{
	int id;
	int bal;
	char name[NAME_LEN];
	cout << "계좌개설을 위한 입력(계좌id  잔액  이름):";
	cin >> id >> bal >> name;
	ac[m] = new Contribution('C', id, bal, name);
	m++;
}
void delete_account(Account** ac, int& m)
{
	int id;
	int n = 0;
	cout << "제거할 계좌 ID: ";
	cin >> id;
	for (int i = 0; i < m; i++)
	{
		if (ac[m] != NULL)
		{
			if (ac[m]->GetId() == id)
			{
				n = 1;
				delete ac[m];
				ac[m] = NULL;
				m++;
				break;
			}
		}
	}
	if (n != 1)
		cout << "계좌 해지 실패!" << endl;
}
void deposit(Account** ac, int& m)
{
	int id,bal;
	int n = 0;
	cout << "계좌 ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> bal;
	for (int i = 0; i < m; i++)
	{
		if (ac[m] != NULL)
		{
			if (ac[m]->GetId() == id)
			{
				ac[m]->InMoney(bal);
				n = 1;
				break;
			}
		}
	}
	if (n != 1)
		cout << "계좌 입금 실패!" << endl;
}
void withdraw(Account** ac, int& m)
{
	int id, bal;
	int n = 0;
	bool k;
	cout << "계좌 ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> bal;
	for (int i = 0; i < m; i++)
	{
		if (ac[m] != NULL)
		{
			if (ac[m]->GetId() == id)
			{
				k = ac[m]->OutMoney(bal);
				if (k == true)
				{
					cout << "현재 잔고는 : " << ac[m]->GetBalance() << endl;
				}
				else
				{
					cout << "잔고가 부족합니다!" << endl << endl;
				}
				n = 1;
				break;
			}
		}
	}
	if (n != 1)
		cout << "계좌 해지 실패!" << endl;
}
void show_all(Account** ac, int m)
{
	for (int i = 0; i < m; i++)
	{
		ac[i]->ShowAllData();
	}
}
void del_mom(Account** ac, int m)
{
	for (int i = 0; i < m; i++)
	{
		if (ac[i] != NULL)
		{
			delete ac[i];
			ac[i] = NULL;
		}
	}
}
void File_Out(Account** ac, int m)
{
	ofstream fout;
	fout.open("Account.txt");
	if (!fout)
	{
		cout << "파일열기 실패!";
	}
	fout << ac[0]->get_public_contribution()<<endl;
	for(int i=0;i<m;i++)
	{
		fout << ac[i]->GetType();
		fout << " ";
		fout << ac[i]->GetId();
		fout << " ";
		fout << ac[i]->GetBalance();
		fout << " ";
		fout << ac[i]->GetName();
		fout << " ";
		if (ac[i]->GetType() == 'C')
			fout << ac[i]->get_private_Contribution() << endl;
		else
			fout << endl;
	}
	fout.close();
}
void File_In(Account** ac, int& m)
{
	int buf1, buf2, buf5, buf6;
	char buf4;
	char buf3[NAME_LEN];
	ifstream fin;
	fin.open("Account.txt");
	if (!fin)
	{
		throw MyException(NULL,"파일이 없습니다!", 0);
	}
	int c;
	fin >> buf6;
	ac[0]->set_public_contribution(buf6);
	while(1)
	{
		fin >> buf4;
		fin >> buf1;
		fin >> buf2;
		fin.getline(buf3, 50, '\n');
		if (buf4 == 'G')
		{
			ac[m] = new Account();
		}
		else if (buf4 == 'S')
		{
			ac[m] = new Saving();
		}
		else if (buf4 == 'C')
		{
			ac[m] = new Contribution();
			fin >> buf5;
			ac[m]->set_private_Contribution(buf5);
		}
		ac[m]->SetId(buf1);
		ac[m]->SetBalance(buf2);
		ac[m]->SetName(buf3);
		m++;
		c = fin.get();
		if (c == EOF)
			break;
	}
}