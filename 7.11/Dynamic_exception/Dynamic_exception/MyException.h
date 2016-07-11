#pragma once
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
class MyException
{
public:
	const void* sender;
	const char* descriprion;
	int info;
	MyException(const void* sender, const char* descriprion, int info)
	{
		this->sender = sender;
		this->descriprion = descriprion;
		this->info = info;
	}
	// virtual void showinfo() const;   // ÇÑ¹ø ÇØºÁ
};
class OutOfRangeException : public MyException
{
public:
	OutOfRangeException(const void* sender, int index)
		:MyException(sender, "Out of Range", index)
	{

	}
	// void showinfo() const;
};
class MemoryException : public MyException
{
public:
	MemoryException(const void* sender, int bytes)
		:MyException(sender, "Out of memory", bytes)
	{

	}
	// void showinfo() const;
};
class StackFullException : public MyException
{
	StackFullException(const void* sender, int index)
		:MyException(sender,"Stack Full!!!",index)
	{

	}
	// void showinfo() const;
};
class StackEmptyException : public MyException
{
	StackEmptyException(const void* sender, int index)
		:MyException(sender, "Stack Empty!!!", index)
	{

	}
	// void showinfo() const;
};
#endif