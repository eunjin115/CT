#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int a, b;

	std::cin >> a >> b;

	std::cout << (a-b);
	return 0;
}