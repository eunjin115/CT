#include <iostream>

int main()
{
	// int x = 1;
	// int y = -x;
	// int z = x / y;

	int x = 7;
	int y = 4;

	std::cout << x / y << "\n"; //실행결과 정수
	//나누는 수 혹은 나눠지는 수 둘 중 하나가 실수라면 결과는 실수로 출력된다. 
	std::cout << float(x) / y << "\n";
	std::cout << x / float(y) << "\n";
	std::cout << float(x) / float(y) << "\n";

	return 0;
}