#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    int answer = 1;
    
    if (dot[0] < 0)
    {
        if (dot[1] < 0)
            return 3;
        else
            return 2;
    }
    if (dot [1] < 0)
        return 4;

    return answer;
}