#include <iostream>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "Miro.h"

#define MAP_ADJ_X 4
#define MAP_ADJ_Y 3
#define MAP_X 30
#define MAP_Y 20

void draw_map();

struct rank {
	char name[20];
	int num;
};

void gotoxy(int x, int y, char* s) {
	COORD pos = { 2 * x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", s);
}

int main() {
	int n;  // ����ġ��
	char seps[] = ","; // �޸�����

	rank s[100] = {
		
	};

	char* token;     // ��ū
	int i = 0;       // ������
	int tmp;         //��ȯ��
	int j;           //2������
	char temp2[10];  //
	int idx;        // �ּڰ�
	int rank[] = { 4,3,2,1 };
	int c=0;
	int miro_count =0;
	std::string miro_name[4];

	// 1. count ����������ְ�
	// 2. �Է¹ް� �迭�� �־��ֱ�



	while (1)
	{
		printf("\t\t\t+------------------------+\n");
		printf("\t\t\t|        POKETMON       |\n");
		printf("\t\t\t+------------------------+\n");

		printf("\t\t\t < PRESS THE NUMBER > \n");

		printf("\t\t\t   1.STAGE GAME   \n");
		printf("\t\t\t   2.MAGE GAME      \n");
		printf("\t\t\t   3.RANGKING         \n");

		scanf("%d", &n);
		if (n == 1)
		{
			//STAGE BATTLE CLASS�� ����
			printf("stage");
		}
		else if (n == 2) {
			system("cls");
			//MAGE BATTLE CLASS�� ����
			MonsterManager *monster[100];
			MonsterManager ab;
			Miro a;

			ab.load_monster(monster);
			Sleep(300);
			int miro_menu = 0;
			while (1)
			{
				if (miro_menu == 4)
					break;
				printf("\t\t\t+------------------------+\n");
				printf("\t\t\t|           MAGE         |\n");
				printf("\t\t\t+------------------------+\n");

				printf("\t\t\t < PRESS THE NUMBER > \n");

				printf("\t\t\t   1.Play         \n");
				printf("\t\t\t   2.Make New Monsters   \n");
				printf("\t\t\t   3.Monster List     \n");
				printf("\t\t\t   4.Exit     \n");
				std::cout << std::endl <<"\t\t\t Menu : ";
				std::cin >> miro_menu;
				Sleep(300);
				system("cls");
				switch (miro_menu)
				{
				case 1:
					miro_name[miro_count] = a.makeShortPath(monster);
					miro_count++;
					break;
				case 2:
					monster[(*monster)->getCount()]->make_monster(monster);
					break;
				case 3:
					for (int i = 0; i < (*monster)->getCount() + 1; i++)
					{
						std::cout << i + 1 << " ";
						monster[i]->getInfo();
					}
					break;
				case 4:
					(*monster)->save_monster(monster, (*monster)->getCount() + 1);
					int n = (*monster)->getCount();
					(*monster)->clear_count();
					for (int i = 0; i < n + 1; i++)
						delete monster[i];
					break;
				}
			}
		}
		else if (n == 3) {

			//ranking system
			//string�� �޾ƿͼ�
			system("cls");
			for (int kk = 0; kk < 4; kk++)
			{
				strcpy(s[kk].name, miro_name[kk].c_str());
			}
			while (i < 4) {                      //��ū�� ����
				token = strtok(s[i].name, seps);
				while (token != NULL) {

					s[i].num = atoi(token);
					if (s[i].num != 0) {

					}
					token = strtok(NULL, seps);
				}
				i++;

			}

			for (c = 0; c < i - 1 ; c++)         // ��������
			{
				idx = c;

				for (j = c + 1; j < i; j++)
				{
					if (s[j].num < s[idx].num)
						idx = j;
				}
				tmp = s[c].num;
				s[c].num = s[idx].num;
				s[idx].num = tmp;
				strcpy(temp2, s[c].name);
				strcpy(s[c].name, s[idx].name);
				strcpy(s[idx].name, temp2);
			}
			printf("\t\t\t\tRANKING\n    ");
			for (c = i - 1; c >= 0; c--)
				printf("\t\t\t  %dst %s %d\n", rank[c], s[c].name, s[c].num);
			getch();
		}
		else if (n == 4) {
			printf("������ �����մϴ�.");
			break;
		}
		else {
			std::cout << "�ٽ� �Է��� �ּ���";
		}
	}
}
