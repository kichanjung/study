#include<iostream>

void doSomething(double* ptr)
{
	if (ptr != nullptr)
	{
		std::cout << *ptr << std::endl;
	}
	else
	{
		std::cout << "Null ptr, do nothing" << std::endl;
	}
}

int main()
{
	double* ptr{ nullptr };

	doSomething(ptr);
	doSomething(nullptr);

	double d = 123.4;

	doSomething(&d);

	ptr = &d;

	doSomething(ptr);

	std::nullptr_t nptr;
	
	return 0;
}