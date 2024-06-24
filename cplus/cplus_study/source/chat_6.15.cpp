#include<iostream>

void doSomething(const int& x)
{
	std::cout << x << std::endl;
}

int main()
{
	int x = 5;
	
	const int ref_x = 3+4;

	doSomething(ref_x);
	doSomething(3 + 4);

	return 0;
}