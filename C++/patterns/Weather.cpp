#include <iostream>
#include <memory>
#include <vector>

class CSubject
{
public:
	CSubject(){}

	virtual void AddOserver(std::shared_ptr<CObserver> _observer) = 0;
	virtual void RemoveObserver(std::shared_ptr<CObserver> _observer) = 0;
	virtual void NotifyObserver() = 0;

};

class CWeather : public CSubject
{
private:
	std::vector<std::shared_ptr<CObserver>> observers;
	float mHumidity, mTemperature;
	int mPressure;
	virtual void NotifyObserver()
	{

	}
public:
	virtual void AddObserver(std::shared_ptr<CObserver> _observer)
	{
		observers.push_back(_observer);
	}
	
	virtual void RemoveObserver(std::shared_ptr<CObserver> _observer)
	{
		for (std::vector<std::shared_ptr<CObserver>>::iterator to_remove = observers.begin(); to_remove != observers.end(); ++to_remove)
		{
			if (*to_remove == _observer)
			{
				observers.erase(to_remove);
				break;
			}
		}
	}

	void SetMeasureChanged(float humidity, int pressure, float temperature)
	{

	}
	void RegisterObserver(CObserver* observer)
	{

	}
	void MeasurementChanged()
	{

	}
};

class CObserver
{

};

int main()
{
	return 0;
}
