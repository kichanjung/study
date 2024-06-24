#include<iostream>
#include "AutoPtr.h"
#include "Resource.h"

AutoPtr<Resource> generateResource()
{
	AutoPtr<Resource> res(new Resource(1000000));

	return res;
}

template<class T>
void MySwap(T& a, T& b)
{
	//T tmp = a;
	//a = b;
	//b = tmp;

	T tmp{ std::move(a) };
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	std::cout.rdbuf(NULL);
	{
		AutoPtr<Resource> main_res;
		main_res = generateResource();
	}
}
