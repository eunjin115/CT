#include<iostream>
using namespace std;
 
class Car {
private:
    int x;
    int y;
public:


    Car(int _x = 0, int _y = 0) : x(_x), y(_y) {}
 
    void Show() {
        cout << x << ", " << y << endl;
    }

	void test(Car c1)
	{
		cout << "x : " << x << " y : " << y << "\n";

		x = c1.x + x;
		y = c1.y + y;

	}
 
    // private 멤버 변수에 접근이 가능하게 하도록 friend로 만들어줌.
    //friend Car operator+(const Car& c1, const Car& c2);
    Car operator+(const Car& c1);
};
 
// 일반 함수를 통한 연산자 재정의
Car Car::operator+(const Car& c1)
{
    // Car tmp;
    // tmp.x = c1.x + c2.x;
    // tmp.y = c1.y + c2.y;
    // return tmp;
	test(c1);
	return *this;
}

Car operator+(const Car& c1, const Car& c2)
{
    Car tmp;
    tmp.x = c1.x + c2.x;
    tmp.y = c1.y + c2.y;
    return tmp;
}

int main() 
{
    Car c1(3, 1);
    Car c2(7, 2);
 
    Car c3 = c1 + c2; // 연산자를 재정의 했기 때문에 가능
    Car c4 = c2 + c1; // 연산자를 재정의 했기 때문에 가능
    c3.Show();
	
 
    return 0;
}