#include <iostream>
#include <string>
#include <memory>

class Duck //오리 interface
{
public:
	virtual void Quack() = 0;
	virtual void Fly() = 0;
};

class MallardDuck : public Duck
{
public:
	virtual void Quack()
	{
		std::cout << "Mallard Duck : Quack Quack \n";
	}
	
	virtual void Fly()
	{
		std::cout << "Mallard Duck : Flapping \n";
	}
};

class Turkey //칠면조 interface
{
public:
	virtual void Gobble() = 0;
	virtual void Fly() = 0;
};

class WildTurkey : public Turkey
{
public:
	virtual void Gobble()
	{
		std::cout << "WildTurkey : Gobble Gobble (like Chales Boyle) \n";
	}
	virtual void Fly()
	{
		std::cout << "WildTurkey : Flapping \n";
	}
};

//Duck 객체가 모자라서 Turkey 객체를 대신 사용해야 하는 상황
//인터페이스가 다르기 떄문에 turkey 객체를 바로 사용할 수 없음

class TurkeyAdapter : public Duck
{
private:
	std::shared_ptr<Turkey> turkey;

public:
	//원래는 생성자에 Turkey 생성자를 호출해서 해당 객체의 멤버 변수에 값을 넣어주는 것도 있지만 이 예제에서는 Turkey 멤버변수로 가진다.
	TurkeyAdapter(std::shared_ptr<Turkey> turkey)
	{
		this->turkey = turkey;
	} 

	void Quack()
	{
		turkey->Gobble();
	}

	void Fly()
	{
		turkey->Fly();
	}
};

int main() //client
{
	std::shared_ptr<Duck> mallard_duck_1 = std::make_shared<MallardDuck>();

	std::shared_ptr<Turkey> wild_turkey = std::make_shared<WildTurkey>();

	mallard_duck_1 -> Quack();
	wild_turkey -> Gobble();

	//앗! 오리가 부족하다~! 그러면 칠면조라도 데리고 와서 싸워야지! (칠면조가 오리 옷 입고 오리 따라하는 것,,)

	std::shared_ptr<Duck> turkey_to_duck = std::make_shared<TurkeyAdapter>(wild_turkey);

	turkey_to_duck -> Quack(); 
	turkey_to_duck -> Fly();

	return 0;
}