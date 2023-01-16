#include <iostream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int n, m;
	cin >> n >> m;

	if (m < 0)
	{
		cout << n + m << '\n';
		cout << n + (m * -1) << '\n';
		cout << n * m;
	}
	else
	{
		cout << n + m << '\n';
		cout << n - m << '\n';
		cout << n * m;
	}
	return 0;
}