#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, result = 0;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; i++)
		cin >> p[i];
	
	sort(p.begin(), p.end());

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
			result += p[j];
	}
	cout << result;
	
	return 0;
}