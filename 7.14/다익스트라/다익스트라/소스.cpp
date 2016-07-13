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
	// 해야하는 것.
	// 1. 각자 짜온 Dijkstra 알고리즘으로 노드를 사용할수 있게끔 포팅할 것.
	// 2. 작동이 되는것이 확인되면, minChoice 부분을 건들거나 응용하여 수를 줄일것.
	// 
	// # STEP 은 이동 수. 디스턴스가 아님
	// # 
	// # 최소 거리를 가장 빨리 찾을것.
}

void showScreen()
{
	_sleep(300);
	system("cls");
	for (auto i = 0; i < 9 + 2; i++)
		std::cout << "■";
	std::cout << std::endl;

	for (int i = 0; i < 9; i++)
	{
		std::cout << "■";
		for (int j = 0; j < 9; j++)
		{
			switch (screen[i][j].status)
			{
			case 1:
				std::cout << "　";
				break;
			case 2:
				std::cout << "○";
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
