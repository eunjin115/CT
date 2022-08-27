#include <iostream>

using namespace std;
int N[6];
int C[6] = {1, 1, 2, 2, 2, 8};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for(int i = 0; i < 6; i++)
	{
		cin >> N[i];
	}
	for (int i = 0; i < 6; i++)
	{
		cout << C[i] - N[i] << ' ';
	}
	return 0;
}