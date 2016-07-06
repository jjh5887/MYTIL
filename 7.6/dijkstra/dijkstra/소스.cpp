#include <iostream>
int m = 100000;
int main()
{
	int G[6][6] = {
		{ 0, 1, m, m, m, m },
		{ 1, 0, 1, m, m, m },
		{ m, 1, 0, 1, 1, m },
		{ m, m, 1, 0, m, 1 },
		{ m, m, 1, m, 0, m },
		{ m, m, m, 1, m, 0 }
	};
	int V[6] = {0};
	for (int i = 1; i < 6; i++)
	{
		V[i] = G[0][i];
	}
	for (int i = 1; i < 6; i++)
	{
		for (int n = i + 1; n < 6; n++)
		{
			if (V[n] > G[i][n]+ G[0][i])
			{
				V[n] = G[i][n] + G[0][i];
				G[0][n] = V[n];
			}
		}
	}
	std::cout << std::endl;
	for (auto i : V)
		std::cout << i << std::endl;
}