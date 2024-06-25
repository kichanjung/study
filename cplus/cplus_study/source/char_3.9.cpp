#include<iostream>
#include<bitset>

int main()
{
	const unsigned apt0 = 1 << 0;
	const unsigned apt1 = 1 << 1;
	const unsigned apt2 = 1 << 2;
	const unsigned apt3 = 1 << 3;

	std::cout << std::bitset<8>(apt0) << std::endl;
	std::cout << std::bitset<8>(apt1) << std::endl;
	std::cout << std::bitset<8>(apt2) << std::endl;
	std::cout << std::bitset<8>(apt3) << std::endl;

	// item0 on
	unsigned char items_flag = 0;
	items_flag |= apt0;
	std::cout << "Item0 obtained" << std::bitset<8>(items_flag) << std::endl;

	items_flag |= apt3;
	std::cout << "Item3 obtained" << std::bitset<8>(items_flag) << std::endl;

	//items_flag &= ~apt0;
	//std::cout << "not Item0 obtained" << std::bitset<8>(items_flag) << std::endl;

	std::cout << "items_flag: " << std::bitset<8>(items_flag) << std::endl;
	std::cout << "apt0: " << std::bitset<8>(apt0) << std::endl;
	if (items_flag & apt0)
	{
		std::cout << "아이템 있음" << std::endl;
	}
	else
		std::cout << "아이템 없음" << std::endl;

	items_flag |= (apt2 | apt3);
	
	std::cout << std::bitset<8>(apt2 | apt3) << std::endl;
	std::cout << "Item2, 3 obtained " << std::bitset<8>(items_flag) << std::endl;


	if ((items_flag & apt2) && !(items_flag & apt1))
	{
		items_flag ^= apt2;
	}


}