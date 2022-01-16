#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, tmp, result = 0;
	int min_value;
	cin >> n >> m;
	vector<vector<int>> card(n * m);

	for (int i = 0; i < n; i++)
	{
		min_value = 10001;
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			min_value = min(min_value, tmp);
		}
		result = max(result, min_value);
	}
	cout << result;

	return 0;
}