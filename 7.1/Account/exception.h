#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H
class MyException
{
public:
	const void* sender;		// 예외를 던진 객체의 주소
	const char* description;	// 예외에 대한 설명
	int info;			// 부가 정보

	MyException(const void* sender, const char* description, int info)
	{
		this->sender = sender;
		this->description = description;
		this->info = info;
	}
};


#endif