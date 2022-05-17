#include <iostream>

int main()
{
	int x = 3;
	int y = 10;
	int z = (++x, ++y); //comma operator

	//콤마 연산자는 다음과 같은 뜻이다.
	//++x;
	//++y;
	//z = y;

	std::cout << x << " " << y << " " << z << "\n";

	int a = 1, b = 10;
	z = a, b;
	std::cout << z;

	return 0;
}