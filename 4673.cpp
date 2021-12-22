#include <iostream>

using namespace std;

int d(int n)
{
	int sum = n;
	while (n != 0)
	{
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}

int main()
{
    bool c[10001] = { false };
 
    for (int i = 1; i <= 10000; i++)
    {
        int k = d(i);
        if(k<=10000)
            c[k] = true;
    }
    for (int j = 1; j <= 10000; j++)
    {
        if (!c[j])
            cout << j << "\n";
    }
	return (0);
}