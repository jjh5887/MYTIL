#include <iostream>
const int N = 5;
int main()
{
	int arr[N][N];
	int n = N;
	bool nega = true;
	int i1 = 0, i2 = 0;
	int k = 0, count = 1, count2 = 0;
	int temp;
	while(k < N*2)
	{
		if (count2 % 3 == 0)
		{
			n--;
		}
		if (count % 3 != 0)
		{
			if (nega == true)
			{
				for (int i = i1; i < n; i++)
				{
					k++;
					arr[i2][i] = k;
					temp = i;
				}
				nega = false;
			}
			else
			{
				i1 = temp;
				for (int i = i2; i < n; i++)
				{
					k++;
					arr[i][i1] = k;
					temp = i;
				}
				nega = true;
			}
		}
		else
		{
			if (nega == true)
			{
				for (int i = n; i > 1; i--)
				{
					k++;
					arr[i2][i] = k;
				}
				nega = false;
			}
			else
			{
				for (int i = n; i > 1; i--)
				{
					k++;
					arr[i][i1] = k;
				}
				nega = true;
			}
		}
		if (count == 3)
			count = 1;
		count2++;
		count++;
	}
	for (int i = 0; i < N; i++)
	{
		for (int m = 0; m < N; m++)
			std::cout << arr[i][m] << " ";
		std::cout << std::endl;
	}
}