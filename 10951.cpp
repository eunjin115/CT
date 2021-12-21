#include <iostream>

using namespace std;

int main()
{
	int n, m;

	// while (cin >> n >> m)
	// {
	// 	cout << n + m << "\n";
	// }

	while ((!cin.eof() && (cin >> n >> m)))
	{
		cout << n + m << "\n";
	}

	return (0);
}