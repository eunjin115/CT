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
	
	tmp = int(m / (k + 1)) * k;
	tmp += m % (k + 1);			//큰 수가 더해지는 경우 

	result += tmp * number[0];
	result += (m - tmp) * number[1];	//m - tmp : 작은 수가 더해질 횟수 


	cout << result;
	return 0;
}