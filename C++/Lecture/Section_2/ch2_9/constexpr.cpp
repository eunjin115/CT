#include <iostream>
#include "constant.h"
int main()
{
	constexpr int my_const(123);

	// int number;
	// std::cin >> number;
	// constexpr int special_number(number); //error

	double radius;
	std::cin >> radius;
	double circumference = 2.0 * radius * constants::pi;
	return 0;
}