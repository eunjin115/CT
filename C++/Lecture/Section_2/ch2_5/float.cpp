#include <iostream>
#include <iomanip>
#include <limits>


int main()
{
	float f;
	double d;
	long double ld;

	std::cout << sizeof(f) << "\n";
	std::cout << sizeof(d) << "\n";
	std::cout << sizeof(ld) << "\n\n";
	
	std::cout << std::numeric_limits<float>::max() << "\n";
	std::cout << std::numeric_limits<double>::max() << "\n";
	std::cout << std::numeric_limits<long double>::max() << "\n";

	return 0;
}