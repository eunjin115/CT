#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p)
{
	int answer = 0;
	long int p_value = stol(p); //stoi 는 int 범위를 벗어나면 읽을 수 없어서 long int 로 변환하는 함수 사용 
	string tmp;
	long int tmp_value = 0;
	for (int i = 0; i < t.length() - p.length() + 1; i++)
	{
		tmp = t.substr(i, p.length());
		tmp_value = stol(tmp); //문자열 t 일부도 stol 으로 잘라오기 
		if (tmp_value <= p_value)
			answer++;
	}
	return answer;
}

int main()
{
	string t = "3141592";
	string p = "271";
	cout << solution(t, p);
	return 0;
}