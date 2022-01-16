#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, result, size;
	string str;
	bool flag;

	result = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		size = str.length();
		flag = true;
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < j; k++)
			{
				if (str[j] != str[j - 1] && str[j] == str[k]) // 같은 단어가 다시 나왔으면 그룹단어 아님
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
			result++;
	}
	cout << result;
}