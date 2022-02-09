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
	Person():id(0){}

	//virtual void work() = 0;
	virtual void work()
	{
		std::cout << "Person Working! \n";
	}

};

class Developer : public Person
{
public:
	virtual void work()
	{
		std::cout << "Developing Working! \n";
	}
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
	std::vector<Person*> Workers;
	Person * p1 =  new Developer;
	Person * p2 =  new Teacher;
	Person * p3 =  new Baker;

	Workers.push_back(p1);
	Workers.push_back(p2);
	Workers.push_back(p3);

	Workers[0]->work();
	Workers[1]->work();
	Workers[2]->work();
	
	return 0;
}