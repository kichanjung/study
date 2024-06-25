#include<iostream>

int main()
{
	constexpr int my_const(123);

	int number;
	std::cin >> number;

	const int special_number(number);
}