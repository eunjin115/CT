#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001] = {0,};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	//int *arr = new int[N]; 으로 동적 할당도 됨 

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int val_max = *max_element(arr, arr + N);
	int val_min = *min_element(arr, arr + N);

	cout << val_min << ' ' << val_max;

	return 0;
}