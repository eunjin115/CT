#include <iostream>
#include <bitset>

int main()
{
	const unsigned int blue_mask = 0x0000FF; // Blue
	const unsigned int green_mask = 0x00FF00; // Gree
	const unsigned int red_mask = 0xFF0000; // Red
	unsigned int pixed_color = 0xDAA520; //gold

	unsigned char blue = pixed_color & blue_mask;
	unsigned char red = (pixed_color & red_mask) >> 16; //16번째 자리에 있으므로 right shift 
	unsigned char green = (pixed_color & green_mask) >> 8; //8번째 자리에 있으므로 right shift

	std::cout << std::bitset<8>(blue) << "\n"; //파란색이 얼마나 포함되어 있는지 확인 가능
	std::cout << std::bitset<8>(red) << "\n"; //파란색이 얼마나 포함되어 있는지 확인 가능
	std::cout << std::bitset<8>(green) << "\n"; //파란색이 얼마나 포함되어 있는지 확인 가능

	return 0;
}