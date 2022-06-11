#include <iostream>
#include <string>

int main()
{
	std::string a = "abcdefg";
	std::cout << a.substr(3, 2) << '\n'; 
	std::cout << a.substr(3, 500) << '\n';
	return 0;
}