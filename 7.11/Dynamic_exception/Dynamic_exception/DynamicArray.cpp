#include <iostream>
#include "DynamicArray.h"
#include "MyException.h"
using namespace std;
DynamicArray::DynamicArray(int arraySize)
{
	arr = new int[arraySize];
	size = arraySize;
}
DynamicArray::~DynamicArray()
{
	delete[] arr;
	arr = NULL;
}
void DynamicArray::SetAt(int index, int value)
{
	if (index < 0 || index >= GetSize())
	{
		throw OutOfRangeException(this,index);
	}
	arr[index] = value;
}
int DynamicArray::GetAt(int index) const
{
	if (index < 0 || index >= GetSize())
	{
		throw OutOfRangeException(this, index);
	}
	return arr[index];
}
int DynamicArray::GetSize() const
{
	return size;
}