#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAX 25

int N;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int house_cnt;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<int> vec;

void DFS(int x, int y)
{
	house_cnt++;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) //맵을 벗어나지 않았다면 
			continue;
		if (arr[nx][ny] == 1 && visited[nx][ny] == false)	//방문하지 않았고 주변이 1이라면 탐색 
		{
			DFS(nx, ny);
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%1d", &arr[i][j]);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1 && visited[i][j] == false)
			{
				house_cnt = 0;
				DFS(i, j);
				vec.push_back(house_cnt);
			}
		}
	}

	sort(vec.begin(), vec.end());
	cout << vec.size() << "\n";

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << "\n";

	return 0;
}