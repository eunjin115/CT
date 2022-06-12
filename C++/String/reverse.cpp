#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string str = "abcdefg";
	std::string str_r (str.rbegin(), str.rend());
	std::cout << str_r  << '\n';

	std::reverse(str.begin(), str.end());
	std::cout << str << '\n';
	return 0;
}