//chain of responsibility pattern

#include <iostream>
#include <memory>

class Person
{
	int id;
	std::string name;
	std::string phone;
public:
	Person(int x, std::string name) : id(x), name(name) {}

	virtual void get_info()
	{
		std::cout << "id : " << id << " name : " << name << "\n";
	}
};

class Researcher : public Person
{
public:
	Researcher(int x, std::string name):Person(x, name){}
};

class Developer : public Person
{
public:
	Developer(int x, std::string name) :Person(x, name) {}
};

class Designer : public Person
{
public:
	Designer(int x, std::string name) :Person(x, name) {}
};

class Analysist : public Person
{
public:
	Analysist(int x, std::string name) :Person(x, name) {}
};



class Job
{

public:
	std::shared_ptr<Job> next = nullptr;

	virtual void Work(std::shared_ptr<Person> p)
	{
		p->get_info();
		std::cout << "Somansa Job \n";
	}

	virtual std::shared_ptr<Job>& setNext(std::shared_ptr<Job> &job)
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
		if (std::dynamic_pointer_cast<Developer>(p)) 
		{
			p->get_info();
			std::cout << "Working at Developing! \n";
			return;
		}
		else
		{
			next->Work(p);
		}
	}
};

class Research : public Job
{
public:

	virtual void Work(std::shared_ptr<Person> p)
	{
		if (std::dynamic_pointer_cast<Researcher>(p))
		{
			p->get_info();
			std::cout << "Working at Researching! \n";
			return;

		}
		else
		{
			next->Work(p);
		}
	}
};

class Analysis : public Job
{
public:

	virtual void Work(std::shared_ptr<Person> p)
	{
		if (std::dynamic_pointer_cast<Analysist>(p))
		{
			p->get_info();
			std::cout << "Working at Analysing! \n";
			return;

		}
		else
		{
			next->Work(p);
		}
	}
};

class Design : public Job
{
public:

	virtual void Work(std::shared_ptr<Person> p)
	{
		if (std::dynamic_pointer_cast<Designer>(p))
		{
			p->get_info();
			std::cout << "Working at designing! \n";
			return;
		}
		else
		{
			next->Work(p);
		}
	}
};


int main()
{
	std::shared_ptr<Person> p1 = std::make_shared<Researcher>(0, "eunjin");
	std::shared_ptr<Person> p2 = std::make_shared<Developer>(1, "calum");

	std::shared_ptr<Job> dev_ptr = std::make_shared<Develop>();
	std::shared_ptr<Job> res_ptr = std::make_shared<Research>();
	std::shared_ptr<Job> ana_ptr = std::make_shared<Analysis>();
	std::shared_ptr<Job> des_ptr = std::make_shared<Design>();


	dev_ptr->setNext(res_ptr)->setNext(ana_ptr)->setNext(des_ptr);

	dev_ptr->Work(p1);
	std::cout << "\n";
	dev_ptr->Work(p2);

	return 0;
}