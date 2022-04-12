#include <iostream>

void func()
{
	std::cout << "func \n";
}

int main()
{
	int i = 123;
	float f = 123.456f;

	//void a; //error
	
	void* my_void;

	my_void = (void *)&i;
	std::cout << my_void << "\n";

	my_void = (float *)&f;
	std::cout << *(float *)my_void << "\n";


	return 0;
}