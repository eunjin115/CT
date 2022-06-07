#include <iostream>

int main()
{
	bool x = true;
	bool y = false;

	std::cout << (x && y) << "\n";

	bool hit = true;
	int health = 10;

	if (hit == true || health < 20) //hit이 true이고 health가 20 미만이라면 
	{
		std::cout << "die \n";
	}
	else
		health -= 20;
	return 0;
}