#include<iostream>
#include<thread>
#include<atomic>
#include<mutex>
#include<chrono>
#include <future>


using namespace std;

mutex mtx;


int main()
{
	//{
	//	int result;
	//	std::thread t([&] {result = 1 + 2; });
	//	t.join();
	//	std::cout << result << std::endl;
	//	return 0;
	//}

	//{
	//	auto fut = std::async([] {return 1 + 2; });
	//	std::cout << fut.get() << std::endl;
	//}
}