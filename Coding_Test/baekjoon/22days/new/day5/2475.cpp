#include <iostream>

using namespace std;

int arr[5];

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	
	long int result = 0;

	for (int i = 0; i < 5; i++)
	{
		result += arr[i] * arr[i];
	}

	result %= 10;

	cout << result;

	return 0;
}