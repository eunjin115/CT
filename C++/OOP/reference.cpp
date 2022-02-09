#include <iostream>

int main()
{
	int a = 4;
	// int &ref = 4;
	int &ref = a;	
	ref = 5;

	std::cout << a <<"\n";
	return 0;
}