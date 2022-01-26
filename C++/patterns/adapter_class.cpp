//adapter pattern - 객체 어댑터 

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

class ClassTurkeyAdapter : public Duck, WildTurkey //클래스 어댑터
{
private:
	std::shared_ptr<WildTurkey> turkey;
public:
	ClassTurkeyAdapter(std::shared_ptr<WildTurkey> _turkey) : turkey(_turkey) {} 
	virtual void Quack()
	{
		turkey->Gobble();
	}
	virtual void Fly()
	{
		turkey->Fly();
	}

};


int main() //client
{
	std::shared_ptr<Duck> mallard_duck_1 = std::make_shared<MallardDuck>();

	std::shared_ptr<WildTurkey> wild_turkey = std::make_shared<WildTurkey>();

	mallard_duck_1 -> Quack();
	wild_turkey -> Gobble();

	std::shared_ptr<ClassTurkeyAdapter> turkey_to_duck = std::make_shared<ClassTurkeyAdapter>(wild_turkey);

	turkey_to_duck -> Quack(); 
	turkey_to_duck -> Fly();

	return 0;
}