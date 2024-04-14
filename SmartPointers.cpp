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

	std::string getName()
	{
		return name;
	}

	~Toy()
	{
		std::cout << "игрушка " << name << " удалена " << std::endl;
	}

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

	void getToy(shared_ptr<Toy> toy)
	{
		if(lovelyToy == toy) {
			std::cout << "I already have this toy." << std::endl; 
		} else if(toy.use_count() > 1){
			std::cout << "Another dog is playing with this toy." << std::endl;
		} else {
			lovelyToy = toy;
			std::cout << "Got a new toy: " << toy->getName() << std::endl;
		}


	}

	void dropToy()
	{
		if(lovelyToy == nullptr) {
			std::cout << "Nothing to drop." << std::endl;
		} else {
			std::cout << "Dropping toy: " << lovelyToy->getName() << std::endl;
			lovelyToy = nullptr;
		}
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
	
	std::shared_ptr<Toy> ball = std::make_shared<Toy>("Ball");
	std::shared_ptr<Toy> bone = std::make_shared<Toy>("Bone");

	Dog dog1;
	Dog dog2;

	dog1.getToy(ball);
	dog2.getToy(bone);

	dog1.getToy(bone);

	dog1.dropToy();


	return 0;
}
