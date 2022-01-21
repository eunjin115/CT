//테스트 코드만 작성하기

#include <iostream>

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass()
	{
		std::cout << "This is Default Constructor \n";
		num1 = 0;
		num2 = 1;
	}

	SimpleClass(int n, int m) : num1(n), num2(m) 
	{
		num1 = 0;
		num2 = 1;
	}

	void print()
	{
		std::cout << "num1 : " << num1 << "\n";
		std::cout << "num2 : " << num2 << "\n";
	}
};


int main()
{
	SimpleClass C(3,4) ;
	C.print();
	std::cout << "--------------------------- \n";
	SimpleClass C1;
	C1.print();
	return 0;
}