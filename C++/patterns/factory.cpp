#include <iostream>
#include <string>
#include <memory>

class Drama
{
private:
	// Factory _factory;
public:
	virtual void print() = 0;
	// Drama(std::string DramaName)
	// {
	// 	_factory = new Factory();
	// 	_factory.CreateDrama(DramaName);
	// }
};

class B99 : public Drama
{
	std::string name;
	std::string position;
public:
	virtual void print()
	{
		// std::cout << name << ": " << job << "\n";
		std::cout << "To the 99! \n";
	}
};

class ModernF : public Drama
{
	std::string name;
	std::string job;
public:
	virtual void print()
	{
		// std::cout << name << ": " << job << "\n";
		std::cout << "Phhhhhhiiiiilllll! \n";
	}

};

class Miranda : public Drama
{
	std::string name;
	std::string job;

public:
	virtual void print()
	{
		// std::cout << name << ": " << job << "\n";
		std::cout << "Such Fuuuuuuuuuuun! \n";
	}

};

class Factory
{
public:
	std::shared_ptr<Drama> CreateDrama(std::string DramaName)
	{	
		std::shared_ptr<Drama> drama;
		if(DramaName == "Brooklyn99")
			drama = std::make_shared<B99>();
		else if (DramaName == "ModernFamily")
			drama = std::make_shared<ModernF>();
		else
			drama = std::make_shared<Miranda>();

		return drama;
	}
};



int main()
{
	std::shared_ptr<Factory> factory = std::make_shared<Factory>();
	std::shared_ptr<Drama> test = factory->CreateDrama("Brooklyn99");

	test->print();


}