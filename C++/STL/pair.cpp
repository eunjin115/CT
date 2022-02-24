#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class Parent
{

};

class Child : public Parent
{

};

int main()
{
	std::vector<std::pair<int, std::string>> v;

	for (int i = 0; i < 3; i++)
	{
		std::string name;
		std::cout << "Input name : ";
		std::cin >> name;
		v.push_back(std::make_pair(i, name));
	}

	std::vector<std::pair<int, std::string>>::iterator iter;
	for (iter = v.begin(); iter!=v.end(); iter++)
		std::cout << "[" << iter->first << "] " << iter->second << "\n";
	
	for (auto a : v)
	{
		std::cout << "[" << a.first << "] " << a.second << "\n";
	}

	std::pair<std::shared_ptr<Parent>, std::shared_ptr<Child>> a;
	return 0;
}