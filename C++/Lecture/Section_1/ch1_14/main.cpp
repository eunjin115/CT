#include <iostream>

#define MAX(a, b) ((a > b) ? a : b)
#define TEST

int main()
{
	std::cout << MAX(1, 3) << "\n";

#ifdef TEST
	std::cout << "TEST! \n";
#endif

#ifndef TEST
	std::cout << "NO TEST! \n";
#endif

	return 0;
}