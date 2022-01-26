#include <iostream>
#include <memory>

class Singleton
{
private:
	Singleton()
	{

	}
	~Singleton()
	{
		
	}
public:
	static std::shared_ptr<Singleton> pInst;
};


