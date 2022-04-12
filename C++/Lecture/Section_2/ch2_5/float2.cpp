#include <iostream>

int main()
{
	float f(3.14);

	std::cout << f << "\n";
	std::cout << 31.4e-1 << "\n";
	std::cout << 31.4e-2 << "\n";
	std::cout << 31.4e1 << "\n"; //31.4 * 10
	std::cout << 31.4e2 << "\n"; //31.4 * 100

	return 0;
}