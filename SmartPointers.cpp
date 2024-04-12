// SmartPointers.cpp: определяет точку входа для приложения.
//

#include "SmartPointers.h"
#include <iostream>
#include <string>

using namespace std;

class Dog
{
	public:
	Dog(string _name, int _age) : name(_name)
	{
		//name = _name;
		if (_age >= 0 && _age < 30) age = _age;
	}

	Dog() : Dog("Unknown", 0) {};
	//{
	//	name = "Uknown";
	//	age = 0;
	//};

	Dog(string _name) : Dog(_name, 0) {};
	Dog(int _age) : Dog("Unknown", _age) {};

	private:
	string name;
	int age;
};

class Wraper
{
	public:
	void func(int i)
	{
		cout << i << " - Целое число" << endl;
	}

	void func(string i)
	{
		cout << i << " - Строка" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Wraper w;
	w.func(10.2);
	w.func("Война и Мир");

	Dog d("Nala", 2.5);
	Dog d1("Pushk");
	Dog d2(11);
	Dog d3();

	

	return 0;
}
