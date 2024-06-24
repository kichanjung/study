#include<iostream>
#include<thread>
#include<atomic>
#include<mutex>
#include<chrono>

using namespace std;

mutex mtx;

int main()
{
	//atomic<int> shared_memory(0);
	int shared_memory(0);
	auto count_func = [&]() {
		for (int i = 0; i < 1000; i++)
		{
			this_thread::sleep_for(chrono::microseconds(1));
			//mtx.lock();
			std::scoped_lock lock(mtx);
			shared_memory++;
			//mtx.unlock();
		}
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);

	t1.join();
	t2.join();

	std::cout << "After" << std::endl;
	std::cout << shared_memory << std::endl;

	return 0;
}