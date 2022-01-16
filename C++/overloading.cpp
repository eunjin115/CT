#include <iostream>
#include <string>

void print(int a)
{
	std::cout << a <<"\n";
}

// void print (char a)
// {
// 	std::cout << a << "\n";
// }

void print (std::string a)
{
	std::cout << a << "\n";
}


int main()
{
	int a = 5;
	char b = 'a';
	std::string c = "Hello World!";

	print(a);
	print(b);
	print(c);

	return 0;
}