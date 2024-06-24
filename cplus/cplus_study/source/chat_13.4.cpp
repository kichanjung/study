#include<iostream>

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

template<>
char getMax(char x, char y)
{
	std::cout << "Warning: chars" << std::endl;
	return (x > y) ? x : y;
}


int main()
{
	std::cout << getMax('a', 'b') << std::endl;
}