#include <iostream>

int main()
{
	int x, y;

	std::cin >> x >> y;

	if (x == y)
		std::cout << "equal" << "\n";
	if (x != y)
		std::cout << "not equal" << "\n";
	if (x >= y)
		std::cout << "x is greater than y or equal to y \n";
	if (x > y)
		std::cout << "x is greater than y \n";
	if (y >= x)
		std::cout << "y is greater than x or equal to x \n";
	if (y > x)
		std::cout << "y is greater than x \n";
		
	return 0;
}