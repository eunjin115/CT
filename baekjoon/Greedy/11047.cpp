#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k, tmp, cnt = 0;
	cin >> n >> k;
	vector<int> coin(n);
	for(int i = 0; i < n; i++)
		cin >> coin[i];

	sort(coin.begin(), coin.end(), greater<int>());
	
	for (int i = 0; i < coin.size(); i++)
	{
		tmp = coin[i];
		cnt += k / tmp;
		k %= tmp;
	}
	cout << cnt;

	return 0;
}