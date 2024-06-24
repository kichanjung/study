#include<iostream>

int main()
{
	int value = 5;
	//const int* ptr = &value;

	//std::cout << *ptr << std::endl;

	int* const ptr = &value;
	int val = 6;
	//ptr = &val;


	return 0;
}