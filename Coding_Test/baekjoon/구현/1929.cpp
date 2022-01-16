#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	bool prime[m + 1];

	for (int i = 0; i <= m; i++)
		prime[i] = true;
	
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i * i <= m; i++)
	{
		if (prime[i])
			for (int j = i * 2; j <= m; j += i)
				prime[j] = false;
	}

	for (int i = n; i <= m; i++)
		if (prime[i])
			cout << i << "\n";

	return 0;
}