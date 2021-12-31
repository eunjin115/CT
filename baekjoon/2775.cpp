#include <iostream>


using namespace std;

int GetPeople(int num1, int num2)
{
	if (num2 == 1)
		return 1;
	if (num1 == 0)
		return num2;
	return (GetPeople(num1 - 1, num2) + GetPeople(num1, num2 - 1));
}


int main()
{
	int n, num1, num2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num1 >> num2;
		cout << GetPeople(num1, num2) << "\n";
	}

	return 0;
}