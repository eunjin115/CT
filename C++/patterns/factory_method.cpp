#include <iostream>
#include <memory>

class DeskProduct //interface
{
public:
	virtual void print() = 0;
};

class Kamil : public DeskProduct //DeskProduct 상속 클래스 
{
public:
	virtual void print()
	{
		std::cout << "Kamil hand & nail cream \n";
	}
};

class Phone : public DeskProduct //DeskProduct 상속 클래스 
{
public:
	virtual void print()
	{
		std::cout << "iPhone XS \n";
	}
};

class Pad : public DeskProduct //DeskProduct 상속 클래스 
{
public:
	virtual void print()
	{
		std::cout << "iPad 6th Generation \n";
	}
};


class Creator //구현 인터페이스 클래스 
{
protected:
	virtual std::shared_ptr<DeskProduct> FactoryMethod() = 0;
public:
	std::shared_ptr<DeskProduct> AnOperation()
	{
		return FactoryMethod();
	}
};

class KamilCreator : public Creator //실제 객체 생성 전달 
{
public:
	virtual std::shared_ptr<DeskProduct> FactoryMethod()
	{
		std::shared_ptr<DeskProduct> concrete_product = std::make_shared<Kamil>();
		return concrete_product;
	}
};

class PhoneCreator : public Creator //실제 객체 생성 전달 
{
public:
	virtual std::shared_ptr<DeskProduct> FactoryMethod()
	{
		std::shared_ptr<DeskProduct> concrete_product = std::make_shared<Phone>();
		return concrete_product;
	}
};


class PadCreator : public Creator //실제 객체 생성 전달 
{
public:
	virtual std::shared_ptr<DeskProduct> FactoryMethod()
	{
		std::shared_ptr<DeskProduct> concrete_product = std::make_shared<Pad>();
		return concrete_product;
	}
};



int main()
{
	std::shared_ptr<Creator> pKamilCreator = std::make_shared<KamilCreator>();
	std::shared_ptr<DeskProduct> pKamil = pKamilCreator->AnOperation();
	pKamil->print();

	std::shared_ptr<Creator> pPhoneCreator = std::make_shared<PhoneCreator>();
	std::shared_ptr<DeskProduct> pPhone = pPhoneCreator->AnOperation();
	pPhone->print();


	std::shared_ptr<Creator> pPadCreator = std::make_shared<PadCreator>();
	std::shared_ptr<DeskProduct> pPad = pPadCreator->AnOperation();
	pPad->print();

	return 0;
}