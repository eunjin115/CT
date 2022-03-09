#include <iostream>

namespace MySpace1
{
	namespace Inner 
	{
		void Act()
		{
			std::cout << "This is Inner Namepsace \n";
		}
	}
	int DoSomething(int a, int b)
	{
		return a * b;
	}
}


int DoSomething(int a, int b)
{
	return a * b;
}

int main()
{
	std::cout << MySpace1::DoSomething(3, 4) << "\n";
	MySpace1::Inner::Act();
	return 0;
}