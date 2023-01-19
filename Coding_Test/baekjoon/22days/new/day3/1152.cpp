#include <iostream>
#include <string>

using namespace std;

int main()
{
	int result = 1;
	string str;

	getline(cin, str);  //string 라이브러리의 getline, 구분자까지 모든 문자열 입력받음 
	
	if (str.empty())
	{
		cout << "0";
		return 0;
	}

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			result++;
	}
	
	//연속된 공백은 없고 문자열 앞뒤에 공백 있을 수도 있으므로 삭제 
	if (str[0] == ' ')
		result--;
	if(str[str.length() - 1] == ' ')
		result--;
	
	cout << result;
	return 0;
}