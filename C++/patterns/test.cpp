#include <iostream>

class A
{
public:
	virtual void Function() = 0;
	virtual void Function1();
	void Function2();
};

class B : public A
{

};

int main()
{
	B b;
	return 0;
}