#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::priority_queue<int> pq;
	pq.push(5);
	pq.push(1);
	pq.push(7); //자동으로 내림차순으로 정렬되어 push 됨

	for (int i = 0; i < 3; i++)
	{
		std::cout << pq.top() << '\n';
		pq.pop();
	}
	
	//올림차순은 다음과 같이 작성한다.
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq_2;
	//vector를 사용하지 않았는데 작성하는 이유는 컨테이너가 vector형으로 구현되서 그런 듯,,,?
	//priority_queu는 따로 컨테이너가 있는 것 보단 vector가  
	pq_2.push(5);
	pq_2.push(1);
	pq_2.push(7);

	for (int i = 0; i < 3; i++)
	{
		std::cout << pq_2.top() << '\n';
		pq_2.pop();
	}

	return 0;
}