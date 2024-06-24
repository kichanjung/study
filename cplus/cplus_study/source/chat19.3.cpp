#include<iostream>
#include<string>
#include<thread>
#include<chrono>
#include<vector>
#include<mutex>

using namespace std;

mutex mtx;

int main01()
{
	//코어 개수
	//cout << std::thread::hardware_concurrency() << std::endl;

	// 스레드 아이디
	std::cout << std::this_thread::get_id() << std::endl;

	const int num_pro = std::thread::hardware_concurrency();

	vector<std::thread> my_threads;

	my_threads.resize(num_pro);

	for (auto& e : my_threads)
	{
		e = std::thread([]() {
			std::cout << std::this_thread::get_id() << std::endl;
			while (true) {}});
	}

	for (auto& e : my_threads)
	{
		e.join();
	}

	return 0;
}

int main()
{
	auto work_func = [](const std::string& name)
		{
			for (int i = 0; i < 5; i++)
			{
				std::this_thread::sleep_for(std::chrono::microseconds(100));

				mtx.lock();
				std::cout << name << " " << std::this_thread::get_id() << "is working " << i << std::endl;
				mtx.unlock();
			}
		};

	std::thread t1 = std::thread(work_func, "juck");
	std::thread t2 = std::thread(work_func, "Dash");

	t1.join();
	t2.join();
}