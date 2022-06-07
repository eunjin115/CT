#include <iostream>
#include <bitset>

int main()
{
	//아래 옵션을 가지고 아이템을 가졌는지 아닌지를 확인할 수 있다
	const unsigned char opt0 = 1 << 0; // 000000001 아이템 0을 가진 상태 정의 (옵션 정의)
	const unsigned char opt1 = 1 << 1; // 000000010 아이템 1을 가진 상태 정의 (옵션 정의)
	const unsigned char opt2 = 1 << 2; // 000000100 아이템 2을 가진 상태 정의 (옵션 정의)
	const unsigned char opt3 = 1 << 3; // 000001000 아이템 3을 가진 상태 정의 (옵션 정의)
	const unsigned char opt4 = 1 << 4; // 000010000 아이템 4을 가진 상태 정의 (옵션 정의)
	const unsigned char opt5 = 1 << 5; // 000100000 아이템 5을 가진 상태 정의 (옵션 정의)
	const unsigned char opt6 = 1 << 6; // 001000000 아이템 6을 가진 상태 정의 (옵션 정의)
	const unsigned char opt7 = 1 << 7; // 010000000 아이템 7을 가진 상태 정의 (옵션 정의)

	unsigned char items_flag = 0;
	std::cout << "No item " << std::bitset<8>(items_flag) << "\n";

	//이벤트 발생으로 item0 생성
	items_flag |= opt0;
	std::cout << "Get item0 " << std::bitset<8>(items_flag) << "\n";

	//item3 획득
	items_flag |= opt3;
	std::cout << "Get item3 " << std::bitset<8>(items_flag) << "\n";

	//item3 잃음
	items_flag &= ~opt3;
	std::cout << "Lost item3 " << std::bitset<8>(items_flag) << "\n";

	//item1이 있는지 확인
	if (items_flag & opt1)
		std::cout << "Has item1 \n";
	else
		std::cout << "No have item 1 \n";
	items_flag |= (opt2 | opt3); //아이템 2와 3을 가지도록 함 
	if ((items_flag & opt2) && (items_flag & opt3))
		std::cout << "Has item2 and 3 \n";
	else
		std::cout << "No have item 2 and 3 \n";
	if ((items_flag & opt2) && !(items_flag & opt1))
	{
		items_flag ^= opt2;
		items_flag ^= opt3;
	}
	return 0;
}