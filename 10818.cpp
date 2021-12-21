#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, val_min, val_max;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	val_min = *min_element(arr, arr+n);
	val_max = *max_element(arr, arr+n);

	cout << val_min << " " <<val_max;
	return (0);
}