//#include <iostream>
//#include <vector>
//#include <memory>
//
//class CSubject
//{
//private:
//	std::vector<std::shared_ptr<CObserver>> observers;
//public:
//	void addObserver(std::shared_ptr<CObserver> _observers)
//	{
//		observers.push_back(_observers);
//	}
//	void removeObserver(std::shared_ptr<CObserver> _observers)
//	{
//		for (std::vector<std::shared_ptr<CObserver>>::iterator to_remove = observers.begin(); to_remove != observers.end(); ++to_remove)
//		{
//			if (*to_remove == _observers)
//			{
//				observers.erase(to_remove);
//				break;
//			}
//		}
//	}
//
//	void notifyObservers()
//	{
//		for (auto o : observers)
//		{
//			if (o != nullptr)
//				o->notify();
//		}
//	}
//};
//
//class CObserver
//{
//public:
//	void notify()
//	{
//		std::cout << "notified \n";
//	}
//};