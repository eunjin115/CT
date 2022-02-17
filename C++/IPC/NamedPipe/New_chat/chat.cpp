#include "Chat.h"

int main()
{
	int type;
	std::cout << "Enter Type : 0 - Server, 1 - Client \n";
	std::cin >> type;
	std::shared_ptr<Chat> tmp;

	if (type)
		tmp = std::make_shared<Client>();
	else
		tmp = std::make_shared<Server>();

	tmp->Initial(); //변수 초기화 

	tmp->Send();
	while (1)
	{

	}
	return 0;
}