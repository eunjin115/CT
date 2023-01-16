#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, result = 0, M, S;

	for (int i = 0; i < 4; i++)
	{
		cin >> T;
		result += T;
	}
	M = result / 60;
	S = result - (60 * M);
	cout << M << '\n' << S;
	return 0;
}