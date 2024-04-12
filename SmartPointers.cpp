// SmartPointers.cpp: определяет точку входа для приложения.
//

#include "SmartPointers.h"
#include <iostream>
#include <string>
#include <clocale>

using namespace std;

class Toy
{
	public:
	Toy(std::string _name) : name(_name) {};
	Toy() : name("SomeToy") {};

	private:
	std::string name;
};


class Dog 
{
public:
	Dog(string _name, std::string toyname, int _age) : name(_name)
	{
		//name = _name;
		if (_age >= 0 && _age < 30) age = _age;
		lovelyToy = new Toy(toyname);
	}

	Dog() : Dog("Unknown", "UnknownToy", 0) {};
	Dog(string _name) : Dog(_name, "UnknownToy", 0) {};
	Dog(int _age) : Dog("Unknown", "UnknownToy", _age) {};

	Dog(const Dog& other) //Конструктор копирования
	{
		name = other.name;
		age = other.age;
		lovelyToy = new Toy(*other.lovelyToy);
	}

	virtual ~Dog()
	{
		delete lovelyToy;
		cout << "Диструктор: удаляю динамическую переменную класса игрушка" << endl;
	}

private:
	string name;
	int age;
	Toy* lovelyToy;
	
	
};


int main()
{
	setlocale(LC_ALL, "rus");
	
	Dog d("drug", "Ball", 1);
	Dog q(d);

	return 0;
}
