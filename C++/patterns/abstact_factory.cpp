#include <iostream>
#include <memory>

//abstract product
class PopUp
{
public:
	virtual void ShowPopUp() = 0;
};

class Scroll
{
public:
	virtual void ShowScroll() = 0;
};

//product

class LinuxPopUp : public PopUp
{
public:
	virtual void ShowPopUp()
	{
		std::cout << "This is Linux PopUp. \n";
	}
};


class WindowsPopUp : public PopUp
{
public:
	virtual void ShowPopUp()
	{
		std::cout << "This is Windows PopUp. \n";
	}
};


class LinuxScroll : public Scroll
{
public:
	virtual void ShowScroll()
	{
		std::cout << "This is Linux Scroll. \n";
	}
};

class WindowsScroll : public Scroll
{
public:
	virtual void ShowScroll()
	{
		std::cout << "This is Windows Scroll. \n";
	}
};

//Abstract Factory
class GUIFactory
{
public:
	virtual std::shared_ptr<PopUp> MakePopUp() = 0;
	virtual std::shared_ptr<Scroll> MakeScroll() = 0;
};

class LinuxGUIFactory : public GUIFactory
{
public:
	virtual std::shared_ptr<PopUp> MakePopUp()
	{
		return std::make_shared<LinuxPopUp>();
	}
	virtual std::shared_ptr<Scroll> MakeScroll()
	{
		return std::make_shared<LinuxScroll>();
	}
};


class WindowsGUIFactory : public GUIFactory
{
public:
	virtual std::shared_ptr<PopUp> MakePopUp()
	{
		return std::make_shared<WindowsPopUp>();
	}
	virtual std::shared_ptr<Scroll> MakeScroll()
	{
		return std::make_shared<WindowsScroll>();
	}
};

class FactoryInstance
{
public:
	static std::shared_ptr<GUIFactory> getGUIFactory(std::string currentOS)
	{
		//현재 무슨 OS인지 구하는 API 대신 string 비교로 대체 
		if (currentOS == "Windows")
		{
			return std::make_shared<WindowsGUIFactory>();
		}
		else
			return std::make_shared<LinuxGUIFactory>();
	}
};

int main()
{
	std::shared_ptr<GUIFactory> factory = FactoryInstance::getGUIFactory("Linux");
	std::shared_ptr<Scroll> scroll = factory->MakeScroll();
	std::shared_ptr<PopUp> popup = factory->MakePopUp();

	scroll->ShowScroll();
	popup->ShowPopUp();

	return 0;
}