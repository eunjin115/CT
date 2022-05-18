#include <iostream>
#include <bitset>

int main()
{
	unsigned int a, b;

	a = 0b1100; //이진수 표현에는 앞에 0b를 붙인다.
	b = 0b0110;

	std::cout << std::bitset<4>(a & b) << "\n";
	std::cout << std::bitset<4>(a | b) << "\n";
	std::cout << std::bitset<4>(a ^ b) << "\n";

	return 0;
}