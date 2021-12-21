#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int* arr = new int[9];
	int max;
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	max = *max_element(arr, arr+9);

	cout << max << "\n" << (find(arr, arr+9, max) - arr) + 1;

	return (0);
}