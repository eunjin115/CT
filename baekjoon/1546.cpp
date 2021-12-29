#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	double max;
	double ans = 0;
	cin >> n;
	double* arr = new double[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	max = *max_element(arr, arr+n);

	for (int i = 0; i < n; i++)
	{
		ans += (arr[i] / max) * 100;
	}
	ans = ans / n;
	cout << ans;
	return (0);	
}