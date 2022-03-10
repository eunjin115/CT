#include <iostream>

int main()
{
	bool b1 = true;
	bool b2 = false;

	std::cout << std::boolalpha;
	std::cout << b1 << "\n";
	std::cout << b2 << "\n";


	if (3 > 1)
		std::cout << "This is true \n";
	else
		std::cout << "This is false \n";
	return 0;
}