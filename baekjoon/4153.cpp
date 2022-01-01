#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c;
	vector <int> square;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		
		square.push_back(a);
		square.push_back(b);
		square.push_back(c);

		int max = *max_element(square.begin(), square.end());
		if (max == c) // c가 제일 큼
		{
			if ((pow((double)a, 2) + pow((double)b, 2)) == pow((double)c, 2))
				cout << "right" << "\n";
			else
				cout << "wrong" << "\n";
		}
		else if (max == a) // a가 제일 큼
		{
			if ((pow((double)c, 2) + pow((double)b, 2)) == pow((double)a, 2))
				cout << "right" << "\n";
			else
				cout << "wrong" << "\n";
		}
		else
		{
			if ((pow((double)c, 2) + pow((double)a, 2)) == pow((double)b, 2)) // b가 제일 큼 
				cout << "right"  << "\n";
			else
				cout << "wrong" << "\n";
		}

		square.clear();
	}

	return 0;
}