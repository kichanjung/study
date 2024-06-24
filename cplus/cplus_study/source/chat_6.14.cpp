#include<iostream>

int main()
{
	//int value = 5;
	//int* ptr = nullptr;
	//ptr = &value;

	//int& ref = value;

	//std::cout << &value << std::endl;
	//std::cout << &ref << std::endl;
	//std::cout << ptr << std::endl;
	//std::cout << &ptr << std::endl;

	int value = 5;
	int* const ptr = &value;
	int& ref = value;

	*ptr = 10;
	ref = 10;

}