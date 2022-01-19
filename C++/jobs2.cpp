#include <iostream>
#include <memory>

class Person
{
	int id;
	std::string name;
	std::string phone;
public:
	Person(int x, std::string name) : id(x), name(name) {}

	void get_info()
	{
		std::cout << "id : " << id << " name : " << name << "\n";
	}
};

class ChairMan : public Person
{
public:
	ChairMan(int x, std::string name):Person(x, name) {}
};

class Researcher : public Person
{
public:
	Researcher(int x, std::string name):Person(x, name){}
};


class Job
{
	std::shared_ptr<Job> next = nullptr;

public:

	virtual void Work(std::shared_ptr<Person> p)
	{
		p->get_info();
		std::cout << "Somansa Job \n";
	}

	std::shared_ptr<Job>& setNext(std::shared_ptr<Job> &job)
	{
		next = job;
		return job;
	}
};

class Develop : public Job
{
public:

	virtual void Work(std::shared_ptr<Person> p)
	{
		p->get_info();
		std::cout << "Working at Developing! \n";
	}
};

class Research : public Job
{
public:

	virtual void Work(Person* p)
	{
		p->get_info();
		std::cout << "Working at Researching! \n";
	}
};

class Analysis : public Job
{
public:

	virtual void Work(Person* p)
	{
		p->get_info();
		std::cout << "Working at Analysing! \n";
	}
};

class Design : public Job
{
public:

	virtual void Work(Person* p)
	{
		p->get_info();
		std::cout << "Working at designing! \n";
	}
};


int main()
{
	std::shared_ptr<Person> p1 = std::make_shared<Researcher>(0, "eunjin");

	std::shared_ptr<Job> dev_ptr = std::make_shared<Develop>();
	std::shared_ptr<Job> res_ptr = std::make_shared<Research>();
	std::shared_ptr<Job> ana_ptr = std::make_shared<Analysis>();
	std::shared_ptr<Job> des_ptr = std::make_shared<Design>();


	dev_ptr->setNext(res_ptr)->setNext(ana_ptr)->setNext(des_ptr);

	dev_ptr->Work(p1);

	return 0;
}