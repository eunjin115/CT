#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(7);
	arr.push_back(7);
	arr.push_back(8);
	arr.push_back(10);

	// std::sort(arr.begin(), arr.end()); //정렬 필요 

	// lower_bound 반환 : iterator - 찾으려고 하는 값과 같거나 큰 위치 반환 
	int a = std::lower_bound(arr.begin(), arr.end(), 5) - arr.begin(); //해당 값이 없으면 그 값 보다 큰 가장 작은 정수 위치 반환
	std::cout << a << "\n";

	//upper_bound 반환 : iterator - 찾으려고 하는 값 초과하는 위치 반환 
	int b = std::upper_bound(arr.begin(), arr.end(), 5) - arr.begin(); //5을 초과하는 수 위치 반환 
	std::cout << b;
	return 0;
}