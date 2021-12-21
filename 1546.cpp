#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, max;
	double ans = 0;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	max = *max_element(arr, arr+n);

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == max)
		{
			ans += arr[i];
			continue;
		}
		ans = ans + (arr[i] / (max * 100));
	}
	ans = ans / n;
	cout << ans;
	return (0);	
}