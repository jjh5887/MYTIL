#include <iostream>
#include "Miro.h"
#include "Battle.hpp"
#include <cstdlib>
#include <ctime>
Miro::Miro()
{
	temp = 1;
	top = -1;
	point = 0;
}

void Miro::initScreen()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			screen[i][j].status = map[i][j];
		}
	}
}

void Miro::setScreen(int _s, int _t)
{
	screen[_s][_t].status = 2;
}

void Miro::clear_screen()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			screen[i][j].visited = 0;
		}
	}
}

void Miro::showScreen()
{
	system("cls");
	for (auto i = 0; i < N + 2; i++)
		std::cout << "■";
	std::cout << std::endl;

	for (int i = 0; i < N; i++)
	{
		std::cout << "■";
		for (int j = 0; j < N; j++)
		{
			switch (screen[i][j].status)
			{
			case 1:
				std::cout << "　";
				break;
			case 2:
				std::cout << "○";
				break;
			case 3:
				std::cout << "  ";
				break;
			default:
				std::cout << "■";
				break;
			}
		}
		std::cout << "■";
		std::cout << std::endl;
	}

	for (auto i = 0; i < N + 2; i++)
		std::cout << "■";
	std::cout << std::endl;
}
std::string Miro::makeShortPath(MonsterManager **player)
{
	srand((unsigned int)time(NULL));
	initScreen();
	clear_screen();

	PlayerManager Mon = choose_monster(player);
	//choose_monster(player).getInfo();
	NODE *node;

	int s = 1, e = 1;
	int battle_num, select_count = 0;
	char choice_num;
	bool top, bottom, left, right;
	visit_screen(&screen[s][temp], s, temp);
	showScreen();

	while (screen[20][11].status != 2)
	{
		top = false;
		bottom = false;
		right = false;
		left = false;
		select_count = 0;
		battle_num = rand() % ((*player)->getCount() + 1);

		if (screen[s][temp + 1].status != 0 && screen[s][temp + 1].visited != true)
			right = true;
		if (screen[s - 1][temp].status != 0 && screen[s - 1][temp].visited != true)
			top = true;
		if (screen[s][temp - 1].status != 0 && screen[s][temp - 1].visited != true)
			left = true;
		if (screen[s + 1][temp].status != 0 && screen[s + 1][temp].visited != true)
			bottom = true;
		std::cout << "방향을 선택하시오 " << std::endl;
		std::cout << "   w " << std::endl;
		std::cout << "a  s  d " << std::endl;
		std::cout << " z : (돌아가기) " << std::endl;
		std::cout << "선택 : ";
		std::cin >> choice_num;
		switch (choice_num)
		{
		case 'd':
			if (!right)
			{
				system("cls");
				showScreen();
				std::cout << "진행할 수 없는 길입니다" << std::endl;
				break;
			}
			if (screen[s][temp + 1].status == 3)
			{
				system("cls");
				std::cout << "배틀 시작!" << std::endl;
				_sleep(100);
				Battle newBattle(Mon, *player[battle_num]);
				if (!(newBattle.start()))
					point = point + 3000;
				else
					point = point - 3000;
			}
			point = point + 500;
			temp++;
			visit_screen(&screen[s][temp], s, temp);
			push(&screen[s][temp]);
			showScreen();
			break;
		case 'w':
			if (!top)
			{
				system("cls");
				showScreen();
				std::cout << "진행할 수 없는 길입니다" << std::endl;
				break;
			}
			if (screen[s - 1][temp].status == 3)
			{
				system("cls");
				std::cout << "배틀 시작!" << std::endl;
				_sleep(100);
				Battle newBattle(Mon, *player[battle_num]);
				if (!(newBattle.start()))
					point = point + 3000;
				else
					point = point - 3000;
			}
			point = point + 500;
			s--;
			visit_screen(&screen[s][temp], s, temp);
			push(&screen[s][temp]);
			showScreen();
			break;
		case 'a':
			if (!left)
			{
				system("cls");
				showScreen();
				std::cout << "진행할 수 없는 길입니다" << std::endl;
				break;
			}
			if (screen[s][temp - 1].status == 3)
			{
				system("cls");
				std::cout << "배틀 시작!" << std::endl;
				_sleep(100);
				Battle newBattle(Mon, *player[battle_num]);
				if (!(newBattle.start()))
					point = point + 3000;
				else
					point = point - 3000;
			}
			point = point + 500;
			temp--;
			visit_screen(&screen[s][temp], s, temp);
			push(&screen[s][temp]);
			showScreen();
			break;
		case 's':
			if (!bottom)
			{
				system("cls");
				showScreen();
				std::cout << "진행할 수 없는 길입니다" << std::endl;
				break;
			}
			if (screen[s + 1][temp].status == 3)
			{
				system("cls");
				std::cout << "배틀 시작!" << std::endl;
				_sleep(100);
				Battle newBattle(Mon, *player[battle_num]);
				if (!(newBattle.start()))
					point = point + 3000;
				else
					point = point - 3000;
			}
			point = point + 500;
			s++;
			visit_screen(&screen[s][temp], s, temp);
			push(&screen[s][temp]);
			showScreen();
			break;
		case 'z':
			node = pop();
			s = node->x;
			temp = node->y;
			node->status = 1;
			showScreen();
			point = point - 600;
		default:
			std::cout << "잘못된 입력입니다." << std::endl;
			break;
		}
	}
	top = -1; // 스택초기화
	temp = 1;
	point = point + 500;
	char a[100];
	itoa(point, a, 10);
	return Mon.getName() + ", " + a;
}
void Miro::visit_screen(NODE* screen, int s, int i)
{
	screen->x = s;
	screen->y = i;
	screen->status = 2;
	screen->visited = 1;
	screen->distance++;
	temp = i;
}

MonsterManager& Miro::choose_monster(MonsterManager **player)
{
	for (int i = 0; i < (*player)->getCount() + 1; i++)
	{
		std::cout << i + 1 << " ";
		player[i]->getInfo();
	}
	std::cout << "미로던전에 쓰일 몬스터를 선택하십시오 : ";
	int n;
	std::cin >> n;
	return *player[n - 1];
}

NODE* Miro::pop()
{
	return (stack[top--]);
}
void Miro::push(NODE *temp)
{
	stack[++top] = temp;
}

