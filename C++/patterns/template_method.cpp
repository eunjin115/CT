#include <iostream>
#include <memory>

class OTT //abstract class
{
private:
	virtual void Drama() = 0;

public:

};

class Netflix : public OTT
{

};

int main()
{

	return 0;
}