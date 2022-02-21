#include <iostream>

int AddNumber(int a, int b)
{
	return a + b;
}

int main()
{
	int a, b;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Input num1 : ";
		std::cin >> a;
		std::cout << "Input num2 : ";
		std::cin >> b;

		std::cout << AddNumber(a, b) << "\n";
	}

	return 0;
}