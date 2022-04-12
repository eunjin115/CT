#include <iostream>
#include <cmath>
#include <limits>

int main()
{
	short s = 1; // 2byte = 2 * 8 bits = 16bits
	unsigned short us = 1;
	int i = 1;
	long l = 1;
	long long ll = 1;

	// std::cout << sizeof(s) << "\n";
	// std::cout << sizeof(i) << "\n";
	// std::cout << sizeof(l) << "\n";
	// std::cout << sizeof(ll) << "\n";

	std::cout << std::pow(2, sizeof(short) * 8 - 1) -1 << "\n";
	std::cout << std::numeric_limits<short>::max() << "\n";
	std::cout << std::numeric_limits<short>::min() << "\n";
	std::cout << std::numeric_limits<short>::lowest() << "\n";

	s = 32767;
	s = s + 1; //32768
	s += 1;
	
	us = 65535;
	us += 1;

	std::cout << s << "\n";
	std::cout << us << "\n";

	return 0;
}