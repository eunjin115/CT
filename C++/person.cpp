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

	~Person() { std::cout << "Person is deleted. \n"; }
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

	std::shared_ptr<Person> dev_ptr = std::shared_ptr<Developer>(new Developer);
	std::shared_ptr<Person> teach_ptr = std::shared_ptr<Teacher>(new Teacher);
	std::shared_ptr<Person> bake_ptr = std::shared_ptr<Baker>(new Baker);

	std::vector<std::shared_ptr<Person>> workers;
	workers.push_back(dev_ptr);
	workers.push_back(teach_ptr);
	workers.push_back(bake_ptr);

	for (int i = 0; i < workers.size(); i++)
		workers[i]->work();

	std::cout << std::endl;

	return 0;
}