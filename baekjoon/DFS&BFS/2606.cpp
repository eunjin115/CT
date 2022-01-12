#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int result = 0;

void dfs(vector<int> *graph, bool *visited, int v)
{
	// 현재 노드를 방문 처리
	visited[v] = true;
	// cout << v << ' '; 테스트 출력
	//  현재 노드와 연결된 다른 노드를 재귀적으로 방문
	for (int i = 0; i < graph[v].size(); i++)
	{
		int y = graph[v][i];
		if (!visited[y])
		{
			dfs(graph, visited, y);
			result++;
		}
	}
}

int main()
{
	int n, m, tmp1, tmp2;
	cin >> n >> m;
	vector<int> graph[n + 1];
	bool visited[n + 1];
	for (int i = 0; i < m; i++)
	{
		cin >> tmp1 >> tmp2;
		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}
	dfs(graph, visited, 1);

	// cout << "\n" << result;
	cout << result;
	return 0;
}