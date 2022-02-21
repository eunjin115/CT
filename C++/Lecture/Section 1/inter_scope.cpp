#include <iostream>

int main()
{
	int x = 0;
	std::cout << "x : " << x << " address : " << &x << std::endl;


	{
		x = 1;
		std::cout << "x : " << x << " address : " << &x << std::endl; //int x가 더 큰 범위라 이 x는 기존에 선언한 범위 밖의 x와 동일하다. 
	}
	
	std::cout << "x : " << x << " address : " << &x << std::endl;

}