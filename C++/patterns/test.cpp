#include <iostream>

class Test
{
private:
    static int a;
public:
    static int GetA()
    {
        a = 10;
        return a;
    }
};

int Test::a = 0;


int main()
{
    Test b;
    std::cout << b.GetA() << "\n";
    return 0;
}