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
	cout << "배열의 크기를 입력하시오 : ";
	cin >> size;
	int* array = new int[size];
	cout << "배열의 원소를 입력하시오 : ";
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
	char q;
	while (1)
	{
		cout << "-----------MENU-----------" << endl;
		cout << "1(선택 정렬)" << endl;
		cout << "2(삽입 정렬)" << endl;
		cout << "3(버블 정렬)" << endl;
		cout << "4(셸 정렬)" << endl;
		cout << "5(합볍 정렬)" << endl;
		cout << "6(퀵 정렬)" << endl;
		cout << "7(히프 정렬)" << endl;
		cout << "8(기수 정렬)" << endl;
		cout << "9(원소 재입력)" << endl;
		cout << "Q(프로그램 종료)" << endl;
		cout << "원하는 작업 선택! :  ";
		cin >> q;
		cout << "현재 배열의 상태 : ";
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
		cout <<"[" << i << "]번 째 요소와 [" << least 
		<< "]번 째 요소 교체" << endl << endl;
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
				cout << "[" << n << "]번 째 요소와 [" << least
					<< "]번 째 요소 교체" << endl << endl;
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
				cout << "[" << i << "]번 째 요소와 [" << n
					<< "]번 째 요소 교체" << endl << endl;
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
				cout << "[" << n << "]번 째 요소와 [" << least
					<< "]번 째 요소 교체" << endl << endl;
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
			cout << k - 1 << "번 째 요소에 " << i - 1 << "번째 요소 대입" << endl;
			show_array(array, right + 1);
		}
		else
		{
			sorted[k++] = array[j++];
			cout << k - 1 << "번 째 요소에 " << j - 1 << "번째 요소 대입" << endl;
			show_array(array, right + 1);
		}
	}
	if (i > mid)
	{
		for (int l = j; l <= right; l++)
		{
			sorted[k++] = array[l];
			cout << k - 1 << "번 째 요소에 " << l << "번째 요소 대입" << endl;
			show_array(array, right + 1);
		}
	}
	else
		for (int l = i; l <= mid; l++)
		{
			sorted[k++] = array[l];
			cout << k - 1 << "번 째 요소에 " << l << "번째 요소 대입" << endl;
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

	// 구간이 1이면 정렬 끝
	if (num <= 1) return;

	// 기준값 결정 : 배열상의 제일 끝 요소
	key = array[num - 1];
	for (left = 0, right = num - 2;; left++, right--) {
		while (array[left] < key) { left++; }
		while (array[right] > key) { right--; }
		if (left >= right) break;           // 좌우가 만나면 끝
		swap(array[left], array[right]);
		cout << "[" << left << "]번 째 요소와 [" << right
			<< "]번 째 요소 교체" << endl << endl;
		show_array(array, num);
	}

	swap(array[left], array[num - 1]);
	cout << "[" << left << "]번 째 요소와 [" << num-1
		<< "]번 째 요소 교체" << endl << endl;
	show_array(array, num);// 기준값과 i위치의 값 교환
	quick_sort(array, left);                     // 왼쪽 구간 정렬
	quick_sort(array + left + 1, num - left - 1);        // 오른쪽 구간 정렬
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
				cout << "[" << cnt << "]번 째 요소와 [" << j
					<< "]번 째 요소 교체" << endl << endl;
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