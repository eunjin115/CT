#include <iostream>

using namespace std;

int main()
{
	int num, cnt = 0;
	int arr[42] = {};	//0으로 초기화 
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		arr[num % 42]++;
	}

	for (int i = 0; i < 42; i++)
	{
		if (arr[i] != 0)
			cnt++; 	//0이 아니라는 건 값이 있다는 것이고 서로 다른 나머지라는 뜻 
	}
	
	cout << cnt << "\n";
	
	return (0);
}