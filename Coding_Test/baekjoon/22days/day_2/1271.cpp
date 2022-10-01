#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	if (m == 0)
		cout << n << '\n' << n;
	else
		cout << n / m << '\n' << n - ((n/m)*m);

	return 0;
}