#include <iostream>

using namespace std;

int count_1;
int count_0;
long long d[100] = {0};

long long fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	if (d[n] != 0)
		return d[n];
	d[n] = fib(n - 1) + fib(n - 2); //계산 결과를 d 배열에 계속 저장하기
	// count++;

	return d[n];
}

long long fib(int n)
{
	if (n == 0)
	{
		count_0++;
		return 0;
	}
	if (n == 1)
	{
		count_1++;
		return 1;
	}
	if  (n == 2)
		return 1;

	if (d[n] != 0)
		return d[n];
	d[n] = fib(n - 1) + fib(n - 2); //계산 결과를 d 배열에 계속 저장하기
	return d[n];
}

int main()
{
	int n;
	int t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		count_1 = 0;
		count_0 = 0;
		cin >> t;
		fib(t);
		cout << count_0 << " " << count_1 << "\n";
	}
	return 0;
}