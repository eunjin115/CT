#include <iostream>
#include <bitset>

int main()
{
	unsigned int a;

	a = 3;
	std::cout << std::bitset<4>(a) << "\n";
	std::cout << std::bitset<4>(~a) << "\n";

	return 0;
}