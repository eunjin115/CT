#include <iostream>
#include <bitset> //비트 관련 라이브러리. (예 - 4자리 이진수로 바로 출력할 수 있도록 하는 라이브러리)

int main()
{
	unsigned int a, b;

	a = 1024;

	std::cout << std::bitset<16>(a << 1) << " " << (a << 1) << "\n";
	std::cout << std::bitset<16>(a << 2) << " " << (a << 2) << "\n";
	std::cout << std::bitset<16>(a << 3) << " " << (a << 3) << "\n";
	std::cout << std::bitset<16>(a << 4) << " " << (a << 4) << "\n";

	return 0;
}