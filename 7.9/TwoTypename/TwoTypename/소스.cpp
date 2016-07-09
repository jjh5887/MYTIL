#include <iostream>
using namespace std;

template <typename T1, typename T2>
class GCLASS {
public:
	T1 data1;
	T2 data2;
	GCLASS();
	void set(T1 a, T2 b);
	void get(T1& a, T2& b);
};
template <typename T1, typename T2>
GCLASS<T1,T2>::GCLASS()
{
	data1 = 0;
	data2 = 0;
}
template <typename T1, typename T2>
void GCLASS<T1, T2>::set(T1 a, T2 b)
{
	data1 = a;
	data2 = b;
}
template <typename T1, typename T2>
void GCLASS<T1, T2>::get(T1& a, T2& b)
{
	a = data1;
	b = data2;
}
class Student
{
public:
	int id;
	char name[100];
	Student();
	Student(int id, char* name);
	// 대입연산자 오버로딩 2개필요, 정수와 자신타입
	Student& operator=(const Student& a);
	Student& operator=(const int& a);
};
Student::Student()
{
	this->id = 0;
	this->name[0] = '\0';
}
Student::Student(int id, char* name)
{
	this->id = id;
	strcpy(this->name, name);
}
Student& Student::operator=(const Student& a)
{
	if (this != &a)
	{
		this->id = a.id;
		strcpy_s(this->name, strlen(a.name) + 1, a.name);
	}
	return *this;
}
Student& Student::operator=(const int& a)
{
	this->id = a;
	this->name[0] = a;
	return *this;
}
int main()
{
	Student s(201533857, "정권호");
	int e = 1000;
	GCLASS<Student, int> z;
	z.set(s, e);
	Student t;
	int f;
	z.get(t, f);
	cout << t.id << " " << t.name << " " << f << endl;
	int a;
	double b;
	GCLASS<int, double> x;
	x.set(2, 0.5);
	x.get(a, b);
	cout << "a : " << a << ", b : " << b << endl;
	char c;
	float d;
	GCLASS<char, float> y;
	y.set('m', 12.5);
	y.get(c, d);
	cout << "c : " << c << ", d : " << d << endl;
}