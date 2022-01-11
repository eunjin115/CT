#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string str;
	vector<string> vec = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
	int idx;

	cin >> str;
	for (int i = 0; i < vec.size(); i++)
	{
		while (1)
		{
			idx = str.find(vec[i]);	//찾은 위치 반환 
			if (idx == string::npos)	//단어 없음 -> 다음 단어로 넘어감 
				break;
			str.replace(idx, vec[i].length(), "#");	//찾은 위치부터 단어 길이까지를 '#' 하나로 바꿈 
		}
	}
	cout << str.length();
}
