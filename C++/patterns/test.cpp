#include <iostream>

class Singleton {
private:
    static Singleton s;
public:
    static Singleton& getIncetance() 
	{
		std::cout <<"what? \n";
        return s;
    }
};

class A {
public:
    A() {
        Singleton& s = Singleton::getIncetance();
    }
};

Singleton Singleton::s; //전역변수로써 초기화

int main(void) {
    //Singleton& s = Singleton::getIncetance();
    A a;
	return 0;
}