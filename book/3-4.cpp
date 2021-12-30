#include <iostream>

using namespace std;


int main()
{
	int n, k, result = 0, cal = 0;
	cin >> n >> k;
	while (!(n == 1))
	{
		if (n % k == 0)
		{
			result++;
			n /= k;
			continue;
		}
		result++;
		n--;
	}
	cout << result;
}