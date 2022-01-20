#include <iostream>
#include <vector>
#include <algorithm>

void BinarySearch(std::vector<int>arr, int x)
{
	int start = 0, end = arr.size(), mid = (start + end) / 2;
	while (start <= end)
	{
		if (arr[mid] == x)
		{
			std::cout << "yes";
			return;
		}
		else if (x < arr[mid])
		{
			end = mid - 1;
		}
		else
			start = mid + 1;
		mid = (start + end) / 2;
	}
	std::cout << "no";
}



int main()
{
	int n, m, x;
	std::vector<int> arr;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());

	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		std::cin >> x;
		BinarySearch(arr, x);
		std::cout << " ";
	}

	return 0;
}