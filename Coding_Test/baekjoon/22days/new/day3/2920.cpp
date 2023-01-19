#include <iostream>
#include <string>

using namespace std;

int main()
{
	int arr[8] = {0, };
	int asc = 0, desc = 0;

	for (int i = 0; i < 8; i++)
		cin >> arr[i];
	
	for (int i = 0; i < 7; i++)
	{
		if (arr[i] < arr[i+1])
			asc++;
		else
			desc++;
	}

	if (asc == 7)
		cout << "ascending";
	else if (desc == 7)
		cout << "descending";
	else
		cout << "mixed";

	return 0; 
}