#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int A, I;
	
	cin >> A >> I;

	cout << A * (I - 1) + 1;
	return 0;
}