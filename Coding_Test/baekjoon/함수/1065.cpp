#include <iostream>

using namespace std;

int check(int n)
{
	int cnt = 0, num1, num2, num3;
	if (n < 100)
		return (n);
	else
	{
		for (int i = 100; i <= n; i++)
		{
			num1 = i / 100;	//백의 자리 숫자
			num2 = (i % 100) / 10; //십의 자리 숫자
			num3 = (i % 100) % 10;	//일의 자리 숫자
			
			if ((num1 - num2) == (num2 - num3))
				cnt++;
		}
		return (99 + cnt);
	}
}


int main()
{
	int n;
	cin >> n;

	cout << check(n);

}