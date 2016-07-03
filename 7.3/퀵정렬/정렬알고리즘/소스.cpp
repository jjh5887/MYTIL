#include <iostream>
#include <vector>

void swap(int& a, int& b);
void show_array(std::vector<int>::iterator iter, int size);
void quick_sort(std::vector<int>::iterator iter, int num);
int main()
{
	int size;
	std::cout << "배열의 크기를 입력하시오 : ";
	std::cin >> size;
	std::vector<int> list;
	int num;
	for (auto i = 0; i < size; i++)
	{
		std::cin >> num;
		list.push_back(num);
	}
	show_array(list.begin(), size);
	quick_sort(list.begin(), size);
	show_array(list.begin(), size);
}
void quick_sort(std::vector<int>::iterator iter, int num)
{
	int left, right;
	int key;

	// 구간이 1이면 정렬 끝
	if (num <= 1) return;

	// 기준값 결정 : 배열상의 제일 끝 요소
	key = iter[num - 1];
	for (left = 0, right = num - 2;; left++, right--) {
		while (iter[left] < key) { left++; }
		while (iter[right] > key) { right--; }
		if (left >= right) break;           // 좌우가 만나면 끝
		swap(iter[left], iter[right]);
		std::cout << "[" << left << "]번 째 요소와 [" << right
			<< "]번 째 요소 교체" << std::endl << std::endl;
		show_array(iter, num);
	}

	swap(iter[left], iter[num - 1]);
	std::cout << "[" << left << "]번 째 요소와 [" << num - 1
		<< "]번 째 요소 교체" << std::endl << std::endl;
	show_array(iter, num);// 기준값과 i위치의 값 교환
	quick_sort(iter, left);                     // 왼쪽 구간 정렬
	quick_sort(iter + left + 1, num - left - 1);        // 오른쪽 구간 정렬
}
void swap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
void show_array(std::vector<int>::iterator iter, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << iter[i] << " ";
	std::cout << std::endl;
}
