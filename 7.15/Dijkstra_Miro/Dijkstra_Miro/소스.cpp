#include <iostream>
const int N = 9;

void algorithm()
{
	// �ؾ��ϴ� ��.
	// 1. ���� ¥�� Dijkstra �˰������� ��带 ����Ҽ� �ְԲ� ������ ��.
	// 2. �۵��� �Ǵ°��� Ȯ�εǸ�, minChoice �κ��� �ǵ�ų� �����Ͽ� ���� ���ϰ�.
	// 
	// # STEP �� �̵� ��. ���Ͻ��� �ƴ�
	// # 
	// # �ּ� �Ÿ��� ���� ���� ã����.
}

typedef struct NODE {
	int x;
	int y;
	int distance;
	int status;
	bool visited;
	struct NODE *s;
}NODE;

void makeShortPath(int s, int e);
//int leastIndex(int arr[], int num);
void initScreen();
void setScreen(int _s, int _t);
void showScreen();
void visit_screen(NODE* screen, int s, int i);

int map[9][9] =
{
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 1, 1, 1, 0 },
	{ 0, 1, 0 ,0, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 1, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 0, 0, 1, 0, 1, 0 },
	{ 0, 1, 1, 1, 0, 1, 1, 1, 0 },
	{ 0, 0, 0, 0 ,0, 0, 0, 1, 0 }
};


int startNode, endNode;
NODE screen[9][9];
int temp;

void main()
{
	initScreen();
	temp = 1;
	makeShortPath(0, 0);
	showScreen();
}

void makeShortPath(int s, int e)
{
	while (screen[8][7].status != 2)
	{
		for (int i = temp; screen[s][i].status != 0; i++)
		{
			if (screen[s][i].status == 1 && screen[s][i].visited != true)
			{
				visit_screen(&(screen[s][i]), s, i);
				showScreen();
			}
		}
		while (screen[s + 1][temp].status == 0 && screen[s - 1][temp].status != 1 && (s != 8 && temp != 7))
		{
			screen[s][temp].status = 1;
			temp--;
			showScreen();
		}
		if (screen[s + 1][temp].visited != true && screen[s + 1][temp].status == 1)
			s++;
		else
			s--;
	}
}
void visit_screen(NODE* screen, int s, int i)
{
	screen->x = s;
	screen->y = i;
	screen->status = 2;
	screen->visited = 1;
	screen->distance++;
	temp = i;
}

void initScreen()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			screen[i][j].status = map[i][j];
		}
	}
}

void setScreen(int _s, int _t)
{
	screen[_s][_t].status = 2;
}

void showScreen()
{
	_sleep(300);
	system("cls");
	for (auto i = 0; i < 9 + 2; i++)
		std::cout << "��";
	std::cout << std::endl;

	for (int i = 0; i < 9; i++)
	{
		std::cout << "��";
		for (int j = 0; j < 9; j++)
		{
			switch (screen[i][j].status)
			{
			case 1:
				std::cout << "��";
				break;
			case 2:
				std::cout << "��";
				break;
			default:
				std::cout << "��";
				break;
			}
		}
		std::cout << "��";
		std::cout << std::endl;
	}

	for (auto i = 0; i < N + 2; i++)
		std::cout << "��";
	std::cout << std::endl;
}

//int leastIndex(int arr[][], int num) {
//	int index, val = arr[0];
//
//	for (int i = 1; i < num; i++) {
//		if (val > arr[i] && visit[i] != 1) {
//			val = arr[i];
//			index = i;
//		}
//	}
//	dist = val;
//	return index;
//}