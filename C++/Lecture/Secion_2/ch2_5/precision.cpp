#include <iostream>
#include <iomanip>

int main()
{
	// std::cout << std::setprecision(16);

	// std::cout << 1.0 / 3.0 << "\n";

	// double d(0.1);
	// std::cout << d << "\n";
	// std::cout << std::setprecision(17);
	// std::cout << d << "\n";

	double d1(1.0);
	double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);

	std::cout << std::setprecision(17);
	std::cout << d1 << "\n";
	std::cout << d2 << "\n";
	return 0;
}