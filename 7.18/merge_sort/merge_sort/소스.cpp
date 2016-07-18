#include <iostream>

void merge_sort(int* array, int left, int right);
void merge(int* array, int left, int mid, int right);
int sorted[100];
void show_array(int* array, int size);

int main()
{
	int array[10];
	std::cout << "배열의 원소를 입력하시오 : ";
	for (int i = 0; i < 10; i++)
		std::cin >> array[i];
	std::cout << "현재 배열의 상태 : ";
	show_array(array, 10);
	merge_sort(array, 0, 9);
	show_array(array, 10);
}

void show_array(int* array, int size)
{
	for(int i = 0 ; i<size ;i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void merge_sort(int* array, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(array, left, mid);
		merge_sort(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}

void merge(int* array, int left, int mid, int right)
{
	int i, j, k;
	i = left; j = mid + 1; k = left;
	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
		{
			sorted[k++] = array[i++];
			std::cout << k - 1 << "번 째 요소에 " << i - 1 << "번째 요소 대입" << std::endl;
			show_array(array, right + 1);
		}
		else
		{
			sorted[k++] = array[j++];
			std::cout << k - 1 << "번 째 요소에 " << j - 1 << "번째 요소 대입" << std::endl;
			show_array(array, right + 1);
		}
	}
	if (i > mid)
	{
		for (int l = j; l <= right; l++)
		{
			sorted[k++] = array[l];
			std::cout << k - 1 << "번 째 요소에 " << l << "번째 요소 대입" << std::endl;
			show_array(array, right + 1);
		}
	}
	else
		for (int l = i; l <= mid; l++)
		{
			sorted[k++] = array[l];
			std::cout << k - 1 << "번 째 요소에 " << l << "번째 요소 대입" << std::endl;
			show_array(array, right + 1);
		}
	for (int l = left; l <= right; l++)
		array[l] = sorted[l];
}