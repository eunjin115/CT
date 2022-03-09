#include <iostream>
// #include <cstdint>

int main()
{
	std::int16_t i(5); //2byte로 변환 
	std::int8_t myint = 65; //char로 변환 됨 

	std::int_fast8_t fi(5);
	std::int_least64_t fl(5);

	return 0;
}