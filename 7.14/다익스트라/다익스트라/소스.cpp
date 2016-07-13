#include <iostream>
const int N = 9;

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

NODE stack[100];
int top = -1;
void push(NODE screen)
{
	stack[++top] = screen;
}
NODE pop()
{
	return stack[--top];
}
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
int dist;
NODE screen[9][9];
NODE parent;
int temp;

void main() 
{

	std::cin >> startNode;
	std::cin >> endNode;
	initScreen();
	temp = 1;
	makeShortPath(startNode, endNode);
	showScreen();
}

void makeShortPath(int s, int e) {
	while(screen[8][7].status != 2)
	{
			for (int i = temp - 1 ; i < 9; i++)
			{
				if (screen[s][i].status == 1 && screen[s][i].visited != true)
				{
					screen[s][i].x = s;
					screen[s][i].y = i;
					screen[s][i].status = 2;
					screen[s][i].visited = 1;
					screen[s][i].distance++;
					temp = i;
					showScreen();
					if (screen[8][7].status == 2)
						exit(0);
				}
			    if (screen[s][i + 1].status == 0)
					break;
			}
			while (screen[s+1][temp].status == 0)
			{
				if (screen[s - 1][temp].status == 1)
				{
					break;
				}
				screen[s][temp].status = 1;
				temp--;
				showScreen();
			}
			if (screen[s+1][temp].visited != true && screen[s + 1][temp].status == 1)
				s++;
			else
				s--;
	}
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
