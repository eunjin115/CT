#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1, str2;

	cin >> str1 >> str2;

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int num1 = atoi(str1.c_str()); //string to char*
	int num2 = atoi(str2.c_str());

	if (num1 > num2)
		cout << num1;
	else 
		cout << num2;

	return 0;
}