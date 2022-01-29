#include <iostream>
#include <memory>


class Person //abstraction -> 기능 계층 인터페이스 
{
	int id;
	std::string name;
public:
	Person(int x, std::string name) : id(x), name(name) {}

	virtual void get_info()
	{
		std::cout << "id : " << id << " name : " << name << "\n";
	}
};

class Job //implementor -> 구현 계층 인터페이스 (Implenetor) & 순서 상 위에 적음,, 
{
public:
	virtual void Work() = 0;
};

class Researcher : public Person //기능 계층 구현 (Concrete Abstractor)
{
private:
	std::shared_ptr<Job> job;
public:
	Researcher(int x, std::string name, std::shared_ptr<Job> _job):Person(x, name), job(_job){}

	void doing()
	{
		job -> Work();
	}

};

class Developer : public Person //기능 계층 구현 (Concrete Abstractor)
{
private:
	std::shared_ptr<Job> job;
public:
	Developer(int x, std::string name, std::shared_ptr<Job> _job):Person(x, name), job(_job){}

	void doing()
	{
		job -> Work();
	}
};



class Develop : public Job //구현 계층 (Concrete Impementor)
{
public:
	virtual void Work()
	{
		std::cout << "Working at Developing! \n";
	}
};

class Research : public Job
{
public:
	virtual void Work()
	{
		std::cout << "Working at Researching! \n";
	}
};


int main()
{
	std::shared_ptr<Person> p1 = std::make_shared<Researcher>(1, "eunjin", std::make_shared<Research>());
	std::shared_ptr<Person> p2 = std::make_shared<Developer>(2, "santiago", std::make_shared<Develop>());

	std::dynamic_pointer_cast<Researcher>(p1)->doing();
	std::dynamic_pointer_cast<Developer>(p2)->doing(); 

	return 0;
}