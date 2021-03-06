#include <iostream>
const int N = 21;

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

NODE* stack[100];
int top = -1;
NODE* pop()
{
	return (stack[top--]);
}
void push(NODE *temp)
{
	stack[++top] = temp;
}

int map[N][N] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0 },
	{ 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0 },
	{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
	{ 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0 },
	{ 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0 },
	{ 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};


int startNode, enfdNode;
NODE screen[21][21];
int temp;

void main()
{
	initScreen();
	temp = 1;
	makeShortPath(1, 1);
	showScreen();
}

void makeShortPath(int s, int e)
{
	NODE *node;
	visit_screen(&screen[s][temp], s, temp);
	showScreen();
	while (screen[20][11].status != 2)
	{
		if (screen[s][temp + 1].status == 1 && screen[s][temp + 1].visited != true)
		{
			temp++;
			visit_screen(&screen[s][temp], s, temp);
			push(&screen[s][temp]);
			showScreen();
		}
		else if (screen[s - 1][temp].status == 1 && screen[s - 1][temp].visited != true)
		{
			s--;
			visit_screen(&screen[s][temp], s, temp);
			push(&screen[s][temp]);
			showScreen();
		}
		else if (screen[s][temp - 1].status == 1 && screen[s][temp - 1].visited != true)
		{
			temp--;
			visit_screen(&screen[s][temp], s, temp);
			push(&screen[s][temp]);
			showScreen();
		}
		else if (screen[s + 1][temp].status == 1 && screen[s + 1][temp].visited != true)
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
	_sleep(150);
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