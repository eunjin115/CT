#include <iostream>

int main()
{
	//conditinal operator (삼항연산자)
	bool onSale;
	onSale = true;

	const int price  = (onSale == true) ? 10 : 100;


	// if(onSale)
	// 	price = 10;
	// else
	// 	price = 100;

	std::cout << price << "\n";

	int x = 5;
	std::cout << ((x % 2 == 0) ? "even" : "odd") << "\n";  

	return 0;
}