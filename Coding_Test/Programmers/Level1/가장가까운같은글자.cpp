#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s)
{
	vector<int> answer;

	for (int i = 0; i < s.length(); i++)
	{
		if (i == 0) //맨 첫번째 글자는 -1
			answer.push_back(-1);
		else
		{
			for (int j = i - 1; j >= -1; j--)
			{
				if (j == -1) //끝까지 없었다면 -1
				{
					answer.push_back(-1);
					break;
				}
				if (s[j] == s[i]) //같았다면 위치 push_back
				{
					answer.push_back(i - j);
					break;
				}
			}
		}
	}
	return answer;
}