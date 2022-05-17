#include <iostream>

int main()
{
	int x = 2;
	int y = 2;

	if (x == 1 && y++ == 2)
	{
		// do something
	}

	std::cout << y << "\n"; //++y가 연산되지 않았음 

	if (x == 2 || y++ == 2)
	{
		//do something
	}

	std::cout << y << "\n"; //++y가 연산되지 않음 

	return 0;
}