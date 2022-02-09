#include <iostream>
#include <vector>
#include <memory>

class Person
{
protected:
	int id;
	std::string name;
	std::string phone;

public:
	Person() : id(0) 
	{
		std::cout << "Person is making now... \n";
	}

	virtual void work()
	{
		std::cout << "Person Working! \n";
	}

	virtual ~Person() { std::cout << "Person is deleted. \n"; }
};

class Developer : public Person
{
public:
	virtual void work()
	{
		std::cout << "Developing Working! \n";
	}
	virtual ~Developer() {std::cout << "Developer is deleted. \n";}
};

class Teacher : public Person
{
public:
	virtual void work()
	{
		std::cout << "Teaching Working! \n";
	}
};

class Baker : public Person
{
public:
	virtual void work()
	{
		std::cout << "Baking Working! \n";
	}
};

int main()
{
	Developer p;
	Person* test = &p;
	test->work();
}