#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int result = 1;

	getline(cin, str);

	if (str.empty())
	{
		cout << "0";
		return 0;
	}
	for(int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			result++;
	}
	if (str[0] == ' ')
		result--;
	if (str[str.length() - 1] == ' ')
		result--;
	cout << result;
}