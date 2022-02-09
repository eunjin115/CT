#include <iostream>
#include <string>

using namespace std;

class test
{
	int a;
	string name;
public:
	test(int x = 0, string str = "test")
	{
		a = x;
		name = str;
	}
	void show()
	{
		cout << "name : " <<name << "\n";
		cout << "a : " << a << "\n";
	}

	test operator+(const test& c) const;

	friend test operator+(const test& t,const test& c);
};

test test::operator+(const test&c) const
{
	test temp(a + c.a);
	return temp;
}


test operator+(const test& t,const test& c)
{
	test temp(t.a + c.a);
	return temp;
}


int main()
{
	test a(1, "eunjin");
	test b(2, "calum");
	test c = a + b;

	c.show();
}