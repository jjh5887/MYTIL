#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H
class MyException
{
public:
	const void* sender;		// ���ܸ� ���� ��ü�� �ּ�
	const char* description;	// ���ܿ� ���� ����
	int info;			// �ΰ� ����

	MyException(const void* sender, const char* description, int info)
	{
		this->sender = sender;
		this->description = description;
		this->info = info;
	}
};


#endif