#include<iostream>
#include<vector>
#include<algorithm>

void testfunc(int& a)
{
	a = 10;
}

int main()
{
	// lambda-introducer

	auto func = [](const int& i) -> void { std::cout << "hello world" << std::endl; };
	int d = 4;
	func(d);

	[&d](int i) -> void {i = 5; d = 500; std::cout << "hello world!" << i << std::endl; }(d);

	std::cout << "d: "<< d << std::endl;

	{
		std::string name = "jeck";
		int b = 1;
		//[b](std::string aa) {std::cout << aa << " " << b << std::endl;  }("name");


		// &없을경우 call by value 와 동일하게 적용
		auto by_value = [&b]() mutable {
			std::cout << "b: " << b << std::endl;
			b = 10;
			};

		by_value();
		std::cout << "b: " << b << std::endl;
	}

	int c = 1;
	testfunc(c);

	std::cout << "c: " << c << std::endl;
}