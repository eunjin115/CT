#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int result;

	result = 0;
	cin >> str;
	for(auto a : str)
	{
		if (a >= 'A' && a <= 'C')
			result+=3;
		else if (a >= 'D' && a <= 'F')
			result+=4;
		else if (a >= 'G' && a <= 'I')
			result += 5;
		else if (a >= 'J' && a <= 'L')
			result += 6;
		else if (a >= 'M' && a <= 'O')
			result += 7;
		else if (a >= 'P' && a <= 'S')
			result += 8;
		else if (a >= 'T' && a <= 'V')
			result += 9;
		else if (a >= 'W' && a <= 'Z')
			result += 10;
		else if (a == '1')
			result += 2;
		else
			result += 11;
	}

	cout << result;
	
}