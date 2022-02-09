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
 
    // private ��� ������ ������ �����ϰ� �ϵ��� friend�� �������.
    //friend Car operator+(const Car& c1, const Car& c2);
    Car operator+(const Car& c1);
};
 
// �Ϲ� �Լ��� ���� ������ ������
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
 
    Car c3 = c1 + c2; // �����ڸ� ������ �߱� ������ ����
    Car c4 = c2 + c1; // �����ڸ� ������ �߱� ������ ����
    c3.Show();
	
 
    return 0;
}