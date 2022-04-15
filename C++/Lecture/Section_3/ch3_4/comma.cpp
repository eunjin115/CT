#include <iostream>

int main()
{
	int x = 3;
	int y = 10;
	int z = (++x, ++y); //comma operator

	std::cout << x << " " << y << " " << z << "\n";

	return 0;
}