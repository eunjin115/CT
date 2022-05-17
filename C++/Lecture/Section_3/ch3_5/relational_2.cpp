#include <iostream>
#include <cmath>

int main()
{
	double d1 = 100 - 99.99;	//0.01
	double d2 = 10 - 9.99; 		//0.01

	std::cout << d1 << "\n" << d2 << "\n\n";
	if (d1 == d2)
		std::cout << "equal \n";
	else
	{
		std::cout << "not equal \n";
		if (d1 < d2)
			std::cout << "d1 < d2 \n";
		else //이미 같지 않다고 판단 했기 때문에 (d2 > d1)
			std::cout << "d2 > d1 \n";
	}

	std::cout << std::abs(d1 - d2) << "\n";

	const double epsilon = 1e-10;
	if (std::abs(d1 - d2) < epsilon)
		std::cout << "Approximately equal \n";
	else
		std::cout << "not equal \n";

	return 0;
}