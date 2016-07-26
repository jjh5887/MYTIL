#include <iostream>

int grap[5][5] = {
	{ 0 ,1, 1, 0, 0 },
	{ 1, 0, 1, 1, 1 },
	{ 1, 1, 0, 1, 1 },
	{ 0, 1, 1, 0, 1 },
	{ 0, 1, 1, 1, 0 }
};
int visit[5][5] = { 0 };
int check(int n)
{
	int count = 0;
	for (int i = 0; i < 5; i++)
		if (visit[n][i] == 1)
			count++;
	return count;
}
int main()
{
	int count = 0;
	for (int i = 0; i < 5; i++)
		for (int n = 0; n < 5; n++)
			if (grap[i][n] == 1)
				count++;
	int n = 3, stop = 0;
	std::cout << n + 1 << " ";
	while (1)
	{
		for (int i = 0; i < 5; i++)
		{
			if (grap[n][i] == 1 && visit[n][i] != 1)
			{
				std::cout << i + 1 << " ";
				visit[n][i] = 1;
				visit[i][n] = 1;
				n = i;
				stop++;
				break;
			}
		}
		if (stop == count / 2)
			break;
	}
}