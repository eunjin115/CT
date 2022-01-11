#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs()
{


}

void bfs()
{

}

int main()
{
	int n, m, v, tmp1, tmp2;
	cin >> n >> m >> v;
	vector<int> graph[n + 1];
	for (int i = 0; i < m; i++)
	{
		cin >> tmp1 >> tmp2;
		graph[tmp1].push_back(tmp2);
	}

}