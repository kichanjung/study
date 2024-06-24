#include<iostream>
#include "Resource.h"
#include "AutoPtr.h"

void doSomething()
{
	try
	{
		AutoPtr<Resource> res = new Resource;
	}
	catch(...)
	{ }
}

int main()
{
	//doSomething();

	AutoPtr<Resource> res1(new Resource);
	AutoPtr<Resource> res2;

	std::cout << std::boolalpha;

	std::cout << res1.m_ptr << std::endl;
	std::cout << res2.m_ptr << std::endl;

	res2 = res1;

	std::cout << res1.m_ptr << std::endl;
	std::cout << res2.m_ptr << std::endl;

	//syntax vs


}