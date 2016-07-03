#include <iostream>
#include <vector>

void swap(int& a, int& b);
void show_array(std::vector<int>::iterator iter, int size);
void quick_sort(std::vector<int>::iterator iter, int num);
int main()
{
	int size;
	std::cout << "�迭�� ũ�⸦ �Է��Ͻÿ� : ";
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

	// ������ 1�̸� ���� ��
	if (num <= 1) return;

	// ���ذ� ���� : �迭���� ���� �� ���
	key = iter[num - 1];
	for (left = 0, right = num - 2;; left++, right--) {
		while (iter[left] < key) { left++; }
		while (iter[right] > key) { right--; }
		if (left >= right) break;           // �¿찡 ������ ��
		swap(iter[left], iter[right]);
		std::cout << "[" << left << "]�� ° ��ҿ� [" << right
			<< "]�� ° ��� ��ü" << std::endl << std::endl;
		show_array(iter, num);
	}

	swap(iter[left], iter[num - 1]);
	std::cout << "[" << left << "]�� ° ��ҿ� [" << num - 1
		<< "]�� ° ��� ��ü" << std::endl << std::endl;
	show_array(iter, num);// ���ذ��� i��ġ�� �� ��ȯ
	quick_sort(iter, left);                     // ���� ���� ����
	quick_sort(iter + left + 1, num - left - 1);        // ������ ���� ����
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
