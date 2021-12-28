#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a = "Hello world";

	for (int i = 0 ; i < 1; i++)
		a.replace(i, i+3, "#");
	cout << a << "\n";

	return (0);
}