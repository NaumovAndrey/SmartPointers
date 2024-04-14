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

class smart_ptr_toy
{
private:
    Toy* obj;
public:
    smart_ptr_toy()
    {
		obj = new Toy("SomeName");
    }

	smart_ptr_toy(std::string name)
	{
		obj = new Toy(name);
	}

	smart_ptr_toy(const smart_ptr_toy& oth) // конструктор копирования
	{
		obj = new Toy(*oth.obj);
	}

	smart_ptr_toy& operator = (const smart_ptr_toy& oth) //оператор присванивания
	{
		if(this = &oth) return *this;
		if(obj != nullptr) delete obj;
		obj = new Toy(*oth.obj);

		return *this;
	}

	~smart_ptr_toy() { delete obj; }; //деструктор
};

class Dog 
{
public:
	Dog(string _name, std::string toyname, int _age) : name(_name), lovelyToy(toyname)
	{
		if (_age >= 0 && _age < 30) age = _age;
	}

	Dog() : Dog("Unknown", "UnknownToy", 0) {};
	Dog(string _name) : Dog(_name, "UnknownToy", 0) {};
	Dog(int _age) : Dog("Unknown", "UnknownToy", _age) {};

	
private:
	string name;
	int age;
	smart_ptr_toy lovelyToy;
};

void foo(std::unique_ptr<Dog> d) {};

int main()
{
	setlocale(LC_ALL, "rus");
	
	std::unique_ptr<Dog> d = std::make_unique<Dog>("Шарик", "Мяч", 1); //один динамический объект - один владелец

	return 0;
}
