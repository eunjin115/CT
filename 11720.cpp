#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, result = 0;
	string str;
	cin >> n;
	cin >> str;

	for (int i = 0; i < n; i++)
	{
		result += str[i] - '0';
	}
	cout << result;

	return 0;
}