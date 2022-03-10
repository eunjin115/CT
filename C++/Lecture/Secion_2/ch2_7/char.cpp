#include <iostream>

int main()
{
	char c1 = 65;
	char c2 = 'A';

	std::cout << c1 << "\n";
	std::cout << c2 << "\n";

	std::cout << int(c1) << "\n";
	std::cout << int(c2) << "\n";
	
	std::cout << static_cast<char>(65) << "\n";
	std::cout << static_cast<int>('A') << "\n";

	return 0;
}