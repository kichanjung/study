#include<iostream>
#include "AutoPtr.h"
#include "Resource.h"

auto doSomething()
{
	return std::make_unique<Resource>(5);
}


int main()
{
	{
		std::unique_ptr<int> upi(new int);

		//auto* ptr = new Resource(5);
		auto res1 = std::make_unique<Resource>(5);

		std::unique_ptr<Resource> res2;

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;
		std::cout << static_cast<bool>(res2) << std::endl;

		res2 = std::move(res1);
		
	}

	{
		Resource* res = new Resource;
		std::unique_ptr<Resource> res1(res);
		std::unique_ptr<Resource> res2(res);

		delete res; // X
	}
}
