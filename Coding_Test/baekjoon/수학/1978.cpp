#include <iostream>

using namespace std;

int main()
{
	int n, tmp, result = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		for (int k = 2; k <= tmp; k++)
		{
			if (tmp % k == 0 && k != tmp)
				break;
			if (k == tmp)
				result++;
		}
	}
	cout << result << "\n";

	return 0;
}