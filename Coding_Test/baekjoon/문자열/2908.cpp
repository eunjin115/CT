#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	string str1_r(str1.rbegin(), str1.rend());
	string str2_r(str2.rbegin(), str2.rend());

	int a = stoi(str1_r);
	int b = stoi(str2_r);

	if (a > b)
		cout << a;
	else
		cout << b;
	
	return 0;
}