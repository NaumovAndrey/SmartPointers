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
		if(this == &oth) return *this;
		if(obj != nullptr) delete obj;
		obj = new Toy(*oth.obj);

		return *this;
	}

	~smart_ptr_toy() { delete obj; }; //деструктор
};

class Dog 
{
public:
	Dog(string _name, std::shared_ptr<Toy> toy, int _age) : name(_name), lovelyToy(toy)
	{
		if (_age >= 0 && _age < 30) age = _age;
	}

	Dog() : Dog("Unknown", std::make_shared<Toy>("UnknownToy"), 0) {};
	Dog(string _name) : Dog(_name, std::make_shared<Toy>("UnknownToy"), 0) {};
	Dog(int _age) : Dog("Unknown", std::make_shared<Toy>("UnknownToy"), _age) {};

	void copyLovelyToy(const Dog& oth)
	{
		lovelyToy = oth.lovelyToy;
	}

	void setBestie(std::shared_ptr<Dog> _bestie)
	{
		bestie = _bestie;
	}
	
private:
	string name;
	int age;
	std::shared_ptr<Toy> lovelyToy;
	std::weak_ptr<Dog> bestie;
};


int main()
{
	setlocale(LC_ALL, "rus");
	
	std::shared_ptr<Toy> ball = std::make_shared<Toy>("Boll");
	std::shared_ptr<Toy> bone = std::make_shared<Toy>("Bone");

	std::shared_ptr<Dog> a = std::make_shared<Dog>("Шарик", ball, 1);
	std::shared_ptr<Dog> b = std::make_shared<Dog>("Дружок", ball, 2);
	std::shared_ptr<Dog> c = std::make_shared<Dog>("Пушок", ball, 8);
	
	a->setBestie(b);
	b->setBestie(c);

	ball.reset(); 
	bone.reset();

	return 0;
}
