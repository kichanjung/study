#include<iostream>
#include "Resource.h"
#include <thread>
#include <vector>
#include <mutex>

 int val = 0;
std::mutex mtx;

void threadFunc(int start, int end)
{
	int sum = 0;
	std::cout << "start: " << start << " " << "end: " << end << std::endl;
	for (int i = start; i <= end; i++)
	{
		sum += i;
	}

	std::lock_guard<std::mutex> lock(mtx);
	std::cout << "sum: " << sum << std::endl;
	val += sum;
}

int main01()
{
	//{
	//	//Resource* res = new Resource(3);
	//	auto ptr1 = std::make_shared<Resource>(3);
	//	ptr1->setAll(1);
	//	//std::shared_ptr<Resource> ptr1(res);

	//	ptr1->print();

	//	{
	//		//std::shared_ptr<Resource> ptr2(ptr1);
	//		//ptr2->setAll(3);
	//		//ptr2->print();
	//		auto ptr2 = ptr1;

	//		std::cout << "block" << std::endl;
	//	}

	//	ptr1->print();
	//	std::cout << "outer" << std::endl;
	//}


	//참조 카운팅
	//auto ptr1 = std::make_shared<int>(10);
	//auto ptr2 = ptr1;
	//auto ptr3 = ptr2;

	//std::cout << "Reference count: " << ptr1.use_count() << std::endl;  // 출력: 3
	//ptr2.reset();  // 참조 카운트 감소
	//std::cout << "Reference count after reset: " << ptr1.use_count() << std::endl;  // 출력: 2

	//ptr3.reset();  // 참조 카운트 감소
	//std::cout << "Reference count after second reset: " << ptr1.use_count() << std::endl;


	//다중 스레드 환경
	//auto ptr = std::make_shared<int>(100);
	///*std::thread t1(threadFunc, ptr);
	//std::thread t2(threadFunc, ptr);*/

	//for (int i = 0; i < 2500; i++)
	//{
	//	std::thread t1(threadFunc, 1);
	//	std::thread t2(threadFunc, 1);
	//}

	////t1.join();
	////t2.join();

	//std::cout << "Main: " << val << std::endl;

	return 0;
}

int main()
{
	std::vector<std::thread> threads;
	int num = 2500;
	int thread_num = 4;

	int start = 1;
	int end = 0;

	int end_point = num / thread_num;

	for (int i = 0; i < thread_num; i++)
	{
		end = start + end_point - 1;
		//if (i == thread_num - 1)
		//	end = num;

		threads.push_back(std::thread(threadFunc, start, end));
		start = end + 1;
	}

	for (auto& th : threads) {
		th.join();
	}

	std::cout << "global: " << val << std::endl;

}