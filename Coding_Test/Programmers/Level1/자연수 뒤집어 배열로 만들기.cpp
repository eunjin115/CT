#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string str;
    str = to_string(n); //long long to string 
    reverse(str.begin(), str.end()); //reverse string 
    for (int i = 0; i < str.length(); i++)
        answer.push_back(str[i] - 48); //ascii 값 빼주기 
    return answer;
}