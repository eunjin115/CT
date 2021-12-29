#include <iostream>
#include <string>

using namespace std;

int main()
{
	int arr[10] = {};	//0으로 초기화 
	int a, b, c, ans;
	cin >> a >> b >> c;
	ans = a * b * c;
	string tmp = to_string(ans);
	for (char ch : tmp)
		arr[ch - '0']++;
	for (int i = 0; i <= 9; i++)
		cout << arr[i] << "\n";
	return (0);
}