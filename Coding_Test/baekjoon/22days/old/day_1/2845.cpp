#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int L, P;
	int N[5];
	cin >> L >> P;
	for (int i = 0; i < 5; i++)
		cin >> N[i];
	for (int i = 0; i < 5; i++)
		cout << N[i] - (L * P) << ' ';
	return 0;
}