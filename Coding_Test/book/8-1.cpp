#include <iostream>

long long d[100] = {0};
// int count = 0;

// int fib(int n)
// {
// 	if (n == 1 || n == 2)
// 		return 1;
// 	return fib(n-1) + fib(n-2);
// }

long long fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	if (d[n] != 0)
		return d[n];
	d[n] = fib(n-1) + fib(n-2); //계산 결과를 d 배열에 계속 저장하기 
	//count++;

	return d[n];
}


int main()
{
	std::cout << fib(100) << "\n";
	// std::cout << count << "\n";
	return 0;
}