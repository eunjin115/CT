#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, x;
	cin >> n;
	vector<int> tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		tmp.push_back(x);
	}
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++)
		cout << tmp[i] << "\n";

	return 0;
}