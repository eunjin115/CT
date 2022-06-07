#include <iostream>
#include <bitset>

int main()
{
	const unsigned char option_viewed = 0x01;
	const unsigned char option_edited = 0x02;
	const unsigned char option_liked = 0x04;
	const unsigned char option_shared = 0x08;
	const unsigned char option_deleted = 0x80;

	unsigned char my_article_flags = 0;

	//기사를 봄
	my_article_flags |= option_viewed;
	std::cout << std::bitset<8>(my_article_flags) << "\n";

	//기사의 좋아요를 눌렀을 때
	my_article_flags |= option_liked;
	std::cout << std::bitset<8>(my_article_flags) << "\n";

	//기사의 좋아요를 다시 눌렀을 때 -> 좋아요가 삭제되어야 함
	my_article_flags ^= option_liked;
	std::cout << std::bitset<8>(my_article_flags) << "\n";

	//본 기사만 삭제할 때
	if (my_article_flags & option_viewed)
		my_article_flags |= option_deleted;
	std::cout << std::bitset<8>(my_article_flags) << "\n";
	
	return 0;
}