#include <iostream>

int main()
{
	bool bValue = false;
	char chValue = 65;
	float fValue = 3.141592f;
	double dValue = 3.141592;

	std::cout << fValue << "\n";
	std::cout << dValue << "\n";

	auto aValue = 3.141592;

	int z = 123; //copy initialization
	int a(123); //direct initialization
	int b{4.5}; //uniform initialization

	int k, l, m = 2; //k와 l은 2로 초기화 되지 않는다. (m만 2로 초기화)
	
	return 0;
}