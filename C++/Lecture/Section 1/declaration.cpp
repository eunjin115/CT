#include <iostream>

int AddTwoNumber(int a, int b); //전방선언

int main()
{
	std::cout << AddTwoNumber(1,2) << "\n";
}

int AddTwoNumber(int a, int b)
{
	return a + b;
}