#include <iostream>
#include <string>

class test
{
	int a,b;
	std::string name;
public:
	test(int x, int y, std::string str);
	//test(const test& copy);

	void show();
};

test::test(int x, int y, std::string str)
{
	std::cout << "call constructor \n";
	a = x;
	b = y;
	name = str;
}

// test::test(const test& copy)
// {
// 	std::cout << "call copy constructor \n";

// 	a = copy.a;
// 	b = copy.b;	
// }

void test::show()
{
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout <<  "\n";
}

int main()
{
	test one(3,3, "eunjin");
	//test two(one);
	test three = one;

	one.show();
	three.show();

}