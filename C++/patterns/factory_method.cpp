#include <iostream>
#include <memory>

//å�� �� ���� - product / �ν��Ͻ� - kamil, phone, pad

class DeskProduct //interface
{
public:
	virtual void print() = 0;
};

class Kamil : public DeskProduct //DeskProduct ��� Ŭ���� 
{
public:
	virtual void print()
	{
		std::cout << "Kamil hand & nail cream \n";
	}
};

class Phone : public DeskProduct //DeskProduct ��� Ŭ���� 
{
public:
	virtual void print()
	{
		std::cout << "iPhone XS \n";
	}
};

class Pad : public DeskProduct //DeskProduct ��� Ŭ���� 
{
public:
	virtual void print()
	{
		std::cout << "iPad 6th Generation \n";
	}
};


class Creator //���� �������̽� Ŭ���� 
{
protected:
	virtual std::shared_ptr<DeskProduct> FactoryMethod() = 0;
public:
	std::shared_ptr<DeskProduct> AnOperation()
	{
		return FactoryMethod();
	}
};

class KamilCreator : public Creator //���� ��ü ���� ���� 
{
public:
	virtual std::shared_ptr<DeskProduct> FactoryMethod()
	{
		std::shared_ptr<DeskProduct> concrete_product = std::make_shared<Kamil>();
		return concrete_product;
	}
};

class PhoneCreator : public Creator //���� ��ü ���� ���� 
{
public:
	virtual std::shared_ptr<DeskProduct> FactoryMethod()
	{
		std::shared_ptr<DeskProduct> concrete_product = std::make_shared<Phone>();
		return concrete_product;
	}
};


class PadCreator : public Creator //���� ��ü ���� ���� 
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
	std::shared_ptr<Creator> kamil_creator = std::make_shared<KamilCreator>();
	std::shared_ptr<DeskProduct> kamil = kamil_creator->AnOperation();
	kamil->print();

	std::shared_ptr<Creator> phone_creator = std::make_shared<PhoneCreator>();
	std::shared_ptr<DeskProduct> phone = phone_creator->AnOperation();
	phone->print();

	std::shared_ptr<Creator> pad_creator = std::make_shared<PadCreator>();
	std::shared_ptr<DeskProduct> pad = pad_creator->AnOperation();
	pad->print();

	return 0;
}