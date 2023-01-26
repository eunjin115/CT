#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int abc[26] = {0};
string str;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < 97) //대문자라면 
			abc[str[i] - 65]++; //65 빼줌 
		else
			abc[str[i] - 97]++; //소문자 -> 97 뺀 인덱스 값 추가 
	}

	//int max = *max_element(abc, abc+26); //max_element쓰기 실패~,,
	int max = 0, max_index = 0;

	for (int i = 0; i < 26; i++)
	{
		if (max < abc[i])
		{
			max = abc[i];
			max_index = i;
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		if (abc[i] == max)
			cnt++;
	}

	if (cnt > 1)
		cout << '?';
	else
		cout << (char)(max_index + 65);
	
	return 0;
}