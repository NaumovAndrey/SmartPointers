// SmartPointers.cpp: определяет точку входа для приложения.
//

#include "SmartPointers.h"
#include <iostream>
#include <string>

using namespace std;

class Toy
{
	public:
	Toy(std::string _name) : name(_name) {};
	Toy() : name("SomeToy") {};

	private:
	std::string name;
};

class Animal
{
public:
	virtual ~Animal()
	{
		std::cout << "диструктор: удаление Animal" << std::endl;
	}

	virtual void voice() = 0;
};

class Dog : public Animal
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

	void voice() override
	{
		std::cout << "Gaf" << std::endl;
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

class OperaDog : public Dog
{
	void voice() override final
	{
		std::cout << "Gaaaaaf" << std::endl;
	}
};


class Wraper
{
	public:
	void func(int i)
	{
		std::cout << i << " - Целое число" << endl;
	}

	void func(string i)
	{
		std::cout << i << " - Строка" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	//Wraper w;
	//w.func(10.2);
	//w.func("Война и Мир");

	/*Dog d("Nala", 2.5);
	Dog d1("Pushk");
	Dog d2(11);
	Dog d3();*/

	Animal* d = new Dog("Sharik", "Ball", 1);
	delete d;

	return 0;
}
