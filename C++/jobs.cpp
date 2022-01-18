#include <iostream>
#include <vector>
#include <memory>
#include <queue>

class Person
{
	int id;
	std::string name;
	std::string phone;

public:
	Person(int x, std::string str) : id(x), name(str)
	{
		//std::cout << "Person is making now... \n";
	}

	void get_info()
	{
		std::cout << "id : " << id << " name : " << name << "\n";
	}

};

class Job
{
public:
	virtual void Work()
	{
		std::cout << "Somansa Job \n";
	}
};

class Develop : public Job
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
	int n;
	std::string working;
	Person p(0, "eunjin");

	std::queue<void> working_queue;

	std::shared_ptr<Job> dev_ptr = std::make_shared<Develop>();
	std::shared_ptr<Job> res_ptr = std::make_shared<Research>();

	std::vector<std::shared_ptr<Job>> jobs;

	jobs.push_back(dev_ptr);
	jobs.push_back(res_ptr);

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> working;
		for (int i = 0; i < jobs.size(); i++)
		{
			if (working == "Research") //Research 클래스라면 
			{
				if (std::dynamic_pointer_cast<Research>(jobs[i]))
				{
					working_queue.push(std::dynamic_pointer_cast<Research>(jobs[i])->Work());
				}
			}
			else
			{
				if (std::dynamic_pointer_cast<Develop>(jobs[i])) //develop 클래스라면 
				{
					working_queue.push(std::dynamic_pointer_cast<Develop>(jobs[i])->Work());
				}
			}
		}
	}
	
	std::cout << "\n\n";
	
	for (int i = 0; i < working_queue.size(); i++)
	{
		working_queue.front();
		working_queue.pop();
	}

}
