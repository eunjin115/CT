#include <iostream>

int main()
{
	int bin(0);
	bin = 0b1; //0000 0001 이진수 = 1 
	bin = 0b11; //0000 0011 이진수 = 3
	bin = 0b1010; //0000 1010 이진수 = 10

	std::cout << bin << "\n";

	return 0;
}