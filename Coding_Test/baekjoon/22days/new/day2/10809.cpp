#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string str;
	std::string alpha = "abcdefghijklmnopqrstuvwxyz";

	std::cin >> str;
	
	for (int i = 0; i < alpha.length(); i++)
	{
		std::cout << (int)str.find(alpha[i]) << ' ';
	}
	return 0;
}