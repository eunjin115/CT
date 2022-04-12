#include <iostream>

int main()
{
	double zero = 0.0;
	double posinf = 5.0 / zero;
	double neginf = -5.0 / zero;
	double nan = zero / zero;

	std::cout << posinf << "\n";
	std::cout << neginf << "\n";
	std::cout << nan << "\n";
	
	return 0;
}