//#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std; 

int main()
{
	vector<int> coin_type = {500,100,50,10};
	int n = 1260, cnt = 0, tmp; 
	for(int i = 0; i < coin_type.size(); i++)
	{
		tmp = coin_type[i];
		cnt += n / tmp;
		n %= tmp;
	}

	cout << cnt;
}