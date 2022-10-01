#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0, tmp = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> tmp;
		ans+=tmp;
	}
	cout << ans;
	return 0;
}