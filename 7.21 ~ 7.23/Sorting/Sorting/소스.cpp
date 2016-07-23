#include <iostream>
using namespace std;

typedef struct
{
	int heap[100];
	int heap_size;
} HeapType;
int sorted[100];
void show_array(int* array, int size);
void swap(int& a, int& b);
void selection_sort(int *array, int size);
void insert_sort(int* array, int size);
void shell_sort(int* array, int size);
void shell_insert_sort(int* array, int size, int gap, int num);
void buble_sort(int* array, int size);
void merge_sort(int* array, int left, int right);
void merge(int* array, int left, int mid, int right);
void quick_sort(int* array, int num);
void initMaxHeap(HeapType *h);
void insertMaxHeap(HeapType *h, int item);
int deleteMaxHeap(HeapType *h);
void heap_sort(int* array, int size);
void radix_sort(int* array, int size, int max);

int main()
{
	int size;
	cout << "�迭�� ũ�⸦ �Է��Ͻÿ� : ";
	cin >> size;
	int* array = new int[size];
	cout << "�迭�� ���Ҹ� �Է��Ͻÿ� : ";
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
	char q;
	while (1)
	{
		cout << "-----------MENU-----------" << endl;
		cout << "1(���� ����)" << endl;
		cout << "2(���� ����)" << endl;
		cout << "3(���� ����)" << endl;
		cout << "4(�� ����)" << endl;
		cout << "5(�պ� ����)" << endl;
		cout << "6(�� ����)" << endl;
		cout << "7(���� ����)" << endl;
		cout << "8(��� ����)" << endl;
		cout << "9(���� ���Է�)" << endl;
		cout << "Q(���α׷� ����)" << endl;
		cout << "���ϴ� �۾� ����! :  ";
		cin >> q;
		cout << "���� �迭�� ���� : ";
		show_array(array, size);
		switch (q)
		{
		case '1':
			selection_sort(array, size);
			break;
		case '2':
			insert_sort(array, size);
			break;
		case '3':
			buble_sort(array, size);
			break;
		case '4':
			shell_sort(array, size);
			break;
		case '5':
			merge_sort(array, 0, size-1);
			break;
		case '6':
			quick_sort(array, size);
			break;
		case '7':
			heap_sort(array, size);
			break;
		case '8':
			radix_sort(array, size, 1);
			break;
		case '9':
			for (int i = 0; i < size; i++)
			{
				cin >> array[i];
			}
			break;
		case 'q':
			exit(0);
		case 'Q':
			exit(0);
		}
		show_array(array, size);
	}
}
void show_array(int* array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}
void swap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
void selection_sort(int *array, int size)
{
	int temp, least;
	for (int i = 0; i < size-1; i++)
	{
		least = i;
		for (int n = i+1; n < size; n++)
		{
			if (array[least] > array[n])
				least = n;
		}
		swap(array[least], array[i]);
		cout <<"[" << i << "]�� ° ��ҿ� [" << least 
		<< "]�� ° ��� ��ü" << endl << endl;
		show_array(array, size);
	}
}
void insert_sort(int* array, int size)
{
	int temp,least;
	for (int i = 0; i < size -1; i++)
	{
		least = i;
		for (int n = i + 1; n > 0; n--)
		{
			if (array[n] < array[least])
			{
				swap(array[n], array[least]);
				cout << "[" << n << "]�� ° ��ҿ� [" << least
					<< "]�� ° ��� ��ü" << endl << endl;
				show_array(array, size);
			}
			least--;
		}
	}
}
void buble_sort(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int n = i + 1; n < size; n++)
		{
			if (array[i] > array[n])
			{
				swap(array[i], array[n]);
				cout << "[" << i << "]�� ° ��ҿ� [" << n
					<< "]�� ° ��� ��ü" << endl << endl;
				show_array(array, size);
			}
		}
	}
}
void shell_sort(int* array, int size)
{
	for (int gap = size / 2; gap > 0; gap = gap / 2)
	{
		if (gap % 2 == 0)
			gap++;
		for (int i = 0; i <= gap; i++)
		{
			shell_insert_sort(array, size, gap, i);
		}
	}
}
void shell_insert_sort(int* array, int size, int gap,int num)
{
	int least;
	for (int i = num + gap; i < size; i = i+gap)
	{
		if (i >= size)
			break;
		least = i;
		for (int n = i + gap; n > 0; n = n - gap)
		{
			if (n >= size)
				break;
			if (array[n] < array[least])
			{
				swap(array[n], array[least]);
				cout << "[" << n << "]�� ° ��ҿ� [" << least
					<< "]�� ° ��� ��ü" << endl << endl;
				show_array(array, size);
			}
			least = least - gap;
		}
	}
}
void merge_sort(int* array, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(array, left, mid);
		merge_sort(array, mid+1, right);
		merge(array, left, mid, right);
	}
}
void merge(int* array, int left, int mid, int right)
{
	int i, j, k;
	cout << mid << endl;
	i = left; j = mid + 1; k = left;
	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
		{
			sorted[k++] = array[i++];
			cout << k - 1 << "�� ° ��ҿ� " << i - 1 << "��° ��� ����" << endl;
			show_array(array, right + 1);
		}
		else
		{
			sorted[k++] = array[j++];
			cout << k - 1 << "�� ° ��ҿ� " << j - 1 << "��° ��� ����" << endl;
			show_array(array, right + 1);
		}
	}
	if (i > mid)
	{
		for (int l = j; l <= right; l++)
		{
			sorted[k++] = array[l];
			cout << k - 1 << "�� ° ��ҿ� " << l << "��° ��� ����" << endl;
			show_array(array, right + 1);
		}
	}
	else
		for (int l = i; l <= mid; l++)
		{
			sorted[k++] = array[l];
			cout << k - 1 << "�� ° ��ҿ� " << l << "��° ��� ����" << endl;
			show_array(array, right+1);
		}
	for (int l = left; l <= right; l++)
		array[l] = sorted[l];
	for (int l = left; l <= right; l++)
		cout << array[l] << endl;
}
void quick_sort(int* array, int num) 
{
	int left, right;
	int key;

	// ������ 1�̸� ���� ��
	if (num <= 1) return;

	// ���ذ� ���� : �迭���� ���� �� ���
	key = array[num - 1];
	for (left = 0, right = num - 2;; left++, right--) {
		while (array[left] < key) { left++; }
		while (array[right] > key) { right--; }
		if (left >= right) break;           // �¿찡 ������ ��
		swap(array[left], array[right]);
		cout << "[" << left << "]�� ° ��ҿ� [" << right
			<< "]�� ° ��� ��ü" << endl << endl;
		show_array(array, num);
	}

	swap(array[left], array[num - 1]);
	cout << "[" << left << "]�� ° ��ҿ� [" << num-1
		<< "]�� ° ��� ��ü" << endl << endl;
	show_array(array, num);// ���ذ��� i��ġ�� �� ��ȯ
	quick_sort(array, left);                     // ���� ���� ����
	quick_sort(array + left + 1, num - left - 1);        // ������ ���� ����
}
void initMaxHeap(HeapType *h)
{
	h->heap_size = 0;
}

void insertMaxHeap(HeapType *h, int item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item > h->heap[i / 2]))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
int deleteMaxHeap(HeapType *h)
{
	int parent, child;
	int item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1]))
			child++;

		if (temp >= h->heap[child])
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void heap_sort(int* array, int size)
{
	HeapType h;
	initMaxHeap(&h);
	for (int i = 0; i < size; i++)
	{
		insertMaxHeap(&h, array[i]);
	}
	for (int i = size - 1; i >= 0; i--)
	{
		array[i] = deleteMaxHeap(&h);
	}
}
void radix_sort(int* array, int size, int max)
{
	int cnt = 0;
	int* temp = new int[size];
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((array[j] / max) % 10 == i)
			{
				temp[cnt] = array[j];
				cout << "[" << cnt << "]�� ° ��ҿ� [" << j
					<< "]�� ° ��� ��ü" << endl << endl;
				cnt++;
			}
		}
	}
	for (int i = 0; i < size; i++)
		array[i] = temp[i];
	for (int i = 0; i < size; i++)
	{
		if (array[i] > max * 10 - 1)
		{
			radix_sort(array, size, max * 10);
			break;
		}
	}
}