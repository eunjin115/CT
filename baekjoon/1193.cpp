#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int i = 1;
	while (n > i)	//몇 번째 대각선에 속해있는지 계산 
	{
		n -= i;
		i++;
	}
	if (i % 2 == 1)	//홀수
		cout << i + 1 - n << '/' << n << "\n";
	else	//짝수 
		cout << n << '/' << i + 1 - n << "\n";
}