#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, time, result = 1;
	cin >> n;

	vector<pair<int, int>> meet_time(n);

	for (int i = 0; i < n; i++)
	{
		//cin >> meet_time[i].first >> meet_time[i].second; //시작시간 : first, 종료시간 : second
		cin >> meet_time[i].second >> meet_time[i].first; //시작시간 : first, 종료시간 : second

	}
	sort(meet_time.begin(), meet_time.end());

	time = meet_time[0].first;
	for (int i = 1; i < n; i++)
	{
		if (meet_time[i].second >= time)
		{
			result++;
			time = meet_time[i].first;
		}
	}
	cout << result;
}