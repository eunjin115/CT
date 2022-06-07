#include <iostream>

int main()
{
	int apple = 5; //이 apple 과

	if (true)
	{
		apple = 1; //이 apple은 동일한 변수 
		std::cout << apple << '\n';
	}
	std::cout << apple << '\n';
	return 0;
}