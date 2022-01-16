#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// DFS 함수 정의
void dfs(vector<int> *graph, bool *visited, int v)
{
	// 현재 노드를 방문 처리
	visited[v] = true;
	cout << v << ' ';
	// 현재 노드와 연결된 다른 노드를 재귀적으로 방문
	for (int i = 0; i < graph[v].size(); i++)
	{
		int y = graph[v][i];
		if (!visited[y])
			dfs(graph, visited, y);
	}
}

void bfs(vector<int> *graph, bool *visited, int v)
{
	queue<int> q;
	q.push(v);
	// 현재 노드를 방문 처리
	visited[v] = true;
	// 큐가 빌 때까지 반복
	while (!q.empty())
	{
		// 큐에서 하나의 원소를 뽑아 출력
		int x = q.front();
		q.pop();
		cout << x << ' ';
		// 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main()
{
	int n, m, v, tmp1, tmp2;
	cin >> n >> m >> v;
	vector<int> graph[n + 1];
	bool visited[n + 1];
	for (int i = 0; i < m; i++)
	{
		cin >> tmp1 >> tmp2;
		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1); //사실 얜 필요 없을수도,,
	}

	for (int i = 1; i <= n; i++) //오름차순으로 sort
		sort(graph[i].begin(), graph[i].end());

	dfs(graph, visited, v);
	cout << "\n";
	for (int i = 0; i <= n; i++)
		visited[i] = false;
	bfs(graph, visited, v);

	return 0;
}