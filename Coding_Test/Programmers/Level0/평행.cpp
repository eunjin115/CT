#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    double m1 = (dots[0][0] - dots[1][0]) / (dots[0][1] - dots[1][1]); //(x1 y1 - x2 y2 기울기)
    double m2 = (dots[2][0] - dots[3][0]) / (dots[2][1] - dots[3][1]); 
    double m3 = (dots[0][0] - dots[2][0]) / (dots[0][1] - dots[2][1]);
    double m4 = (dots[1][0] - dots[3][0]) / (dots[1][1] - dots[3][1]);
    
    if (m1 == m2 && m3 == m4)
        return 1;
	
	//두 직선이 겹치는 경우는 작성하지 않았는데 통과 함

    return answer;
}

int main()
{

	vector<vector<int>> test = {{1, 4}, {9, 2}, {3, 8}, {11, 6}};

	cout << solution(test);
	return 0;
}