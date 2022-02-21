#include <iostream>

void DoSomething(int x)
{
	x = 123;
	std::cout << x << std::endl;
}

int main()
{
	int x = 0;

	std::cout << x << std::endl;
	DoSomething(x);
	std::cout << x << std::endl;

	return 0;
}