#include <iostream>
#include <memory>

class OTT //abstract class
{
protected:
	virtual void Drama() = 0;
	virtual void Movie() = 0;
	virtual void HookFunc() {}; //사실 얘는 없어도 되지 않을까..? 
public:
	void OttView()
	{
		Drama();
		Movie();
		HookFunc();
	}

};

class Netflix : public OTT //Concrete Class
{
protected:
	virtual void Drama()
	{
		std::cout << "********************* \n";
		std::cout << "Netflix Original Drama\n";
		std::cout << "*Unbreakable kimmy schmidt \t *Narcos \t *Umbralla Academy \n"; 
	}
	virtual void Movie()
	{
		std::cout << "********************* \n";
		std::cout << "Neflix Original Movie \n";
		std::cout << "*6 Underground \t *Kissing booth \n";
	}
	virtual void HookFunc()
	{
		std::cout << "Netflix HookFunc \n";
	}
};

class Disney : public OTT
{
protected:
	virtual void Drama()
	{
		std::cout << "********************* \n";
		std::cout << "Disney+ Original Drama \n";
		std::cout << "*Loky \t *Falcon \t *WandaVision \n";
	}
	virtual void Movie()
	{
		std::cout << "********************* \n";
		std::cout << "Disney Movie \n";
		std::cout << "*Marvel Cinematic Universe \n";
	}
	virtual void HookFunc()
	{
		std::cout << "Disney HookFunc \n";
	}
};

class Watcha : public OTT
{
protected:
	virtual void Drama()
	{
		std::cout << "********************* \n";
		std::cout << "Watcha Exclusive Drama \n";
		std::cout << "*Why Women Kill? \n";
	}
	virtual void Movie()
	{
		std::cout << "********************* \n";
		std::cout << "Watcha Exclusive Movie \n";
		std::cout << "*Harry Potter \n";
	}
	virtual void HookFunc()
	{
		std::cout << "Watcha HookFunc \n";
	}
};

int main()
{
	std::shared_ptr<OTT> netflix = std::make_shared<Netflix>();
	netflix->OttView();

	std::shared_ptr<OTT> disney = std::make_shared<Disney>();
	disney->OttView();

	std::shared_ptr<OTT> watcha = std::make_shared<Watcha>();
	watcha->OttView();

	return 0;
}