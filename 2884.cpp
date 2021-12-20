#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int h, m, dif;
	cin >> h >> m;
	dif = 0;

	if (m >= 45)
	{
		cout << h << " " << m-45;
	}
	else
	{
		if (h == 0) h = 24;
		h--;
		dif = abs(m - 45);
		m = 60 - dif;
		cout << h << " " << m;
	}

	return (0);
}