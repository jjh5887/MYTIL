#include <iostream>
#include "DynamicArray.h"
#include "MyException.h"
using namespace std;
void UseArray(DynamicArray& arr, DynamicArray& arr2);
int main()
{
	DynamicArray arr(10), arr2(8);
	UseArray(arr, arr2);
	return 0;
}
void UseArray(DynamicArray& arr, DynamicArray& arr2)
{
	try
	{
		arr.SetAt(5, 100);
		arr2.SetAt(5, 100);

		arr.SetAt(8, 10);
		arr2.SetAt(8, 10);

		arr.SetAt(10, 200);
		arr2.SetAt(10, 200);

		throw MemoryException(NULL, 1000); // 메모리 부족 상황 연출!
	}
	catch (MyException& ex)
	{
		cout << "&arr = " << &arr << endl;
		cout << "&arr2 = " << &arr2 << endl;
		cout << "예외를 던진 객체의 주소 : " << ex.sender << endl;
		cout << "예외에 대한 설명 :" << ex.descriprion << endl;
		cout << "부가정보 : " << ex.info << endl;
	}
}