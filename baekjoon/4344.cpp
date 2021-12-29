#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, sum = 0, cnt = 0;

		cin >> x;
		int arr[x];	//점수 받아옴 
		for (int j = 0; j < x; j++)
		{
			cin >> arr[j];
			sum += arr[j];	//합계 계산 
		}
		double avg = ((double) sum / (double)x);	//평균 계산, 꼭 double끼리 계산해줘야 함 
		for (int j = 0; j < x; j++)
		{
			if (avg < arr[j])	//평균을 넘는다면 cnt증가
				cnt++;
		}
		cout.precision(3);
		cout << fixed;

		cout << (cnt / (double)x) * 100 << "%\n"; //평균을 넘는 학생 수 비율 계산   
	}

	return (0);
}