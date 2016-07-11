#pragma once
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
class DynamicArray
{
public:
	int * arr;
	int size;
public:
	DynamicArray(int arraySize);
	~DynamicArray();
	void SetAt(int index, int value);
	int GetAt(int index) const;
	int GetSize() const;
};
#endif