#include <iostream>

int main()
{
	int sum = 0;
	int i = 1;
	int count;
	int temp;

	while (1)
	{
		count = 0;
		sum += i;
		temp = (int)sqrt(sum);
		for (int n = 1; n <= temp - 1; n++)
		{
			if (sum%n == 0)
			{
				count++;
			}
		}
		if (count >= 250)
			break;
		i++;
		std::cout << sum << std::endl;

	}
	std::cout << sum;
}
