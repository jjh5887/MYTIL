#include <iostream>
#include "Miro.h"

Miro::Miro()
{
	temp = 1;
	top = -1;
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

void Miro::showScreen()
{
	_sleep(500);
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
				std::cout << "X";
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
void Miro::makeShortPath()
{
	NODE *node;
	int s = 1, e = 1;
	visit_screen(&screen[s][temp], s, temp);
	showScreen();
	while (screen[20][11].status != 2)
	{
		if (screen[s][temp].status == 3)
		{
			std::cout << "배틀 시작!" << std::endl;
			break;
		}
		if (screen[s][temp + 1].status != 0 && screen[s][temp + 1].visited != true)
		{
			temp++;
			visit_screen(&screen[s][temp], s, temp);
			push(&screen[s][temp]);
			showScreen();
		}
		else if (screen[s - 1][temp].status != 0 && screen[s - 1][temp].visited != true)
		{
			s--;
			visit_screen(&screen[s][temp], s, temp);
			push(&screen[s][temp]);
			showScreen();
		}
		else if (screen[s][temp - 1].status != 0 && screen[s][temp - 1].visited != true)
		{
			temp--;
			visit_screen(&screen[s][temp], s, temp);
			push(&screen[s][temp]);
			showScreen();
		}
		else if (screen[s + 1][temp].status != 0 && screen[s + 1][temp].visited != true)
		{
			s++;
			visit_screen(&screen[s][temp], s, temp);
			push(&screen[s][temp]);
			showScreen();
		}
		else
		{
			node = pop();
			s = node->x;
			temp = node->y;
			node->status = 1;
			showScreen();
		}
	}
	top = -1; // 스택초기화
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
NODE* Miro::pop()
{
	return (stack[top--]);
}
void Miro::push(NODE *temp)
{
	stack[++top] = temp;
}