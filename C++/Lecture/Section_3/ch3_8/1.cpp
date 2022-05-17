#include <iostream>
#include <bitset> //비트 관련 라이브러리. (예 - 4자리 이진수로 바로 출력할 수 있도록 하는 라이브러리)

int main()
{
	unsigned int a;

	a = 3;
	std::cout << std::bitset<4>(a) << "\n"; //4bit 출력
	
	return 0;
}