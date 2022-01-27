#include <iostream>
#include <memory>
#include <string>

class SingletonPrint
{
private:
	static std::shared_ptr<SingletonPrint> pInst; //객체를 참조 할 정적 참조변수 
	SingletonPrint() //생성자를 외부에서 사용하지 못하도록 함 
	{

	}
	~SingletonPrint()
	{
		
	}
public:
	static std::shared_ptr<SingletonPrint> GetInstance()
	{
		if (pInst == nullptr)
		{
			pInst = std::make_shared<SingletonPrint>();
		}
		return pInst;
	}

	void printing(std::string str)
	{
		std::cout << "Printing now : " << str << "\n";
	}

};

int main()
{
	std::shared_ptr<SingletonPrint> print = SingletonPrint::GetInstance();
	print->printing("You know even when i said moved on \n");

	return 0;
}