#include <iostream>
#include <memory>

//명령패턴 -> 함수 호출을 객체로 감싼다 : Invoker (Handler) 객체로 호출을 감싼다. 

class Command //명령 interface 
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
};

class Ingredient : public Command //명령 interface 구현 
{
private:
	std::string ingredient;
	std::string amount;
public:
	Ingredient(std::string _ingredient, std::string _amount) : ingredient(_ingredient), amount(_amount) {}
	virtual void execute()
	{
		std::cout << "*Add " << amount << " of " << ingredient << "\n";
	}
};

class Step : public Command //명령 interface 구현 
{
private:
	std::string action;
public:
	Step(std::string _action) : action(_action) {}

	virtual void execute()
	{
		std::cout << "*Doing : " << action << "\n";
	}
};

class InputHandler //핸들러 구현 -> 명령 실행 
{
public:
	void HandlerInput(std::shared_ptr<Command> command)
	{
		command->execute();
	}
}; 

int main()
{
	std::shared_ptr<InputHandler> handler = std::make_shared<InputHandler>();

	handler->HandlerInput(std::make_shared<Ingredient>("Coffe Power", "200g"));
	handler->HandlerInput(std::make_shared<Ingredient>("Hot Water", "500ml"));
	handler->HandlerInput(std::make_shared<Step>("Setting Coffe Filter"));
	handler->HandlerInput(std::make_shared<Step>("Putting Coffe Power into Filter"));
	handler->HandlerInput(std::make_shared<Step>("Pouring Hot Water into Filter"));

	return 0;
}