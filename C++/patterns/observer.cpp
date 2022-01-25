#include <iostream>
#include <memory>
#include <vector>

class Observer
{
public:
	virtual void Update(float power) = 0;
};

class Subject
{
public:
	virtual void AddObserver(std::shared_ptr<Observer> observer) = 0;
	virtual void RemoveObserver(std::shared_ptr<Observer> observer) = 0;
	virtual void NotifyObserver() = 0;

};

class EarthQuake : public Subject
{
private:

	std::vector<std::shared_ptr<Observer>> Observers;
	float power;

public:

	EarthQuake(float n) : power(n) {}

	virtual void AddObserver(std::shared_ptr<Observer> observer)
	{
		Observers.push_back(observer);
	}

	virtual void RemoveObserver(std::shared_ptr<Observer> observer)
	{
		for (std::vector<std::shared_ptr<Observer>>::iterator to_remove = Observers.begin(); to_remove != Observers.end(); to_remove++)
		{
			if (*to_remove == observer)
			{
				Observers.erase(to_remove);
				break;
			}
		}
	}

	virtual void NotifyObserver()
	{
		for (std::vector<std::shared_ptr<Observer>>::iterator iter = Observers.begin(); iter != Observers.end(); iter++)
		{
			std::shared_ptr<Observer> observer = *iter;
			observer->Update(power);
		}

	}

	void SetPower(float _power)
	{
		power = _power;
		if (power > 2.0)
			NotifyObserver();
	}

};


class SeoulObserver : public Observer
{
private:
	float seoul_power;
public:
	SeoulObserver()
	{
		seoul_power = 0;
	}
	virtual void Update(float power)
	{
		seoul_power = power;
		std::cout << "An EarthQuake occurred in Seoul. \n";
	}
};

class LondonObserver : public Observer
{
private:
	float london_power;
public:
	LondonObserver()
	{
		london_power = 0;
	}
	virtual void Update(float power)
	{
		london_power = power;
		std::cout << "An EarthQuake occurred in London. \n";
	}
};

int main()
{
	std::shared_ptr<Subject> Earth = std::make_shared<EarthQuake>((float)0);

	std::shared_ptr<Observer> seoul = std::make_shared<SeoulObserver>();
	std::shared_ptr<Observer> london = std::make_shared<LondonObserver>();

	Earth->AddObserver(seoul);
	Earth->AddObserver(london);


	std::dynamic_pointer_cast<EarthQuake>(Earth)->SetPower(1.0);
	std::dynamic_pointer_cast<EarthQuake>(Earth)->SetPower(4.0);

	return 0;

}