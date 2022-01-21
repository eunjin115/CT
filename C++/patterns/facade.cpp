#include <iostream>
#include <memory>

class Person
{
	int id;
	std::string name;

public:
	Person(int x, std::string name) : id(x), name(name) {}

	void get_info()
	{
		std::cout << "id : " << id << " name : " << name << "\n";
	}
};

class Wash
{
public:
	Wash(std::shared_ptr<Person> p)
	{
		p->get_info();
		std::cout << "Taking shower \n";
	}
};

class Breakfast
{
public:
	Breakfast(std::shared_ptr<Person> p)
	{
		p->get_info();
		std::cout << "Eating Breakfast \n";
	}
};

class Move
{
public:
	Move(std::shared_ptr<Person> p)
	{
		p->get_info();
		std::cout << "Walking to Office \n";
	}
};

class GoOffice
{
public:
	GoOffice(std::shared_ptr<Person> p)
	{
		std::shared_ptr<Wash> wash_ptr = std::make_shared<Wash>(p);
		std::shared_ptr<Breakfast> eat_ptr = std::make_shared<Breakfast>(p);
		std::shared_ptr<Move> move_ptr = std::make_shared<Move>(p);
	}
};


int main()
{
	std::shared_ptr<Person> p1 = std::make_shared<Person>(0, "eunjin");

	std::shared_ptr<GoOffice> wash_ptr = std::make_shared<GoOffice>(p1);

	return 0;
}