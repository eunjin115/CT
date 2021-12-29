#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, k, tmp = 0, result = 0;
	cin >> n >> m >> k;
	vector<int> number(n);
	
	for (int i = 0; i < n; i++)
		cin >> number[i];
	sort(number.begin(), number.end(), greater<int>()); 	//내림차순 정렬
	
	for(int i = 0; i < m; i++)
	{
		if (tmp < k)
		{
			result+= number[0];
			tmp++;
			continue;
		}
		result+= number[1];
		tmp = 0;
	}

	cout << result;

	return 0;
}