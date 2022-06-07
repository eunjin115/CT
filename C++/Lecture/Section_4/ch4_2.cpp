#include <iostream>

int a = 1;
// int a = 1; //같은 변수가 선언되었으므로 중복 선언.

namespace work1 //scope로 정의하여 내용은 다르지만 같은 함수를 정의하기 위해 네임스페이스 사용
{
	int a = 1;
	void dosomething() //같은 영역에 두 함수가 있으므로 에러. 
	{
		a += 5;
		std::cout << a << '\n';
	}
} // namespace work1

namespace work1::work11::work111
{
	int a = 1;
	void dosomething()
	{
		a += 3;
		std::cout << a << '\n';
	}
}

namespace work2
{
	int a = 1;
	void dosomething()
	{
		a += 3;
		std::cout << a << '\n';
	}

} // namespace work2


// { //scope를 이용해서 정의를 하면 같은 함수로 인식하지 않으나 지역을 벗어나면 없어지므로 에러 
// 	void dosomething() //같은 영역에 두 함수가 있으므로 에러. 
// 	{
// 		a += 5;
// 	}
// }
// void dosomething()
// {
// 	a += 3;
// }

int main()
{
	int apple = 5; //이 appel 과 

	if (true)
	{
		int apple = 1; //이 apple은 다른 변수 
		std::cout << apple << '\n';
	}
	std::cout << apple << '\n';

	work1::a; //work1의 a 선언
	work1::dosomething();

	work2::a;
	work2::dosomething();

	return 0;
}