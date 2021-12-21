#include <iostream>

using namespace std;

int main()
{
	int n, a, b, ans = 0, tmp = 0, cnt = 0;

	cin >> n;
	tmp = n;

	if (n == 0)
	{
		cout << "1";
		return (0);
	}

	while (!(ans == tmp))
	{
		a = n / 10;
		b = n % 10; 
		ans = a + b;
		b = b * 10;
		a = ans % 10;
		ans = a + b;
		n = ans;
		cnt++;
	}

	cout << cnt;

	return (0);
}