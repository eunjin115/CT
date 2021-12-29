#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> card(n * m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> card[i][j];
		}
		//sort(card[i].begin(), card[i].end(), greater<int>()); 	//내림차순 정렬
	}
	
}