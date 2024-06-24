#include<chrono>
#include<iostream>
#include<mutex>
#include<random>
#include<thread>
#include<utility>
#include<vector>
#include<atomic>
#include<future>
#include<numeric>
#include<execution>

using namespace std;

mutex mtx;

void dotProductNaive(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
	for (unsigned i = i_start; i < i_end; i++)
	{
		sum = v0[i] + v1[i];
	}
}

void dotProductNaiveLock(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
	for (unsigned i = i_start; i < i_end; i++)
	{
		//std::lock_guard lock(mtx);
		mtx.lock();
		sum = v0[i] + v1[i];
		mtx.unlock();
	}
}

void dotProductNaiveAt(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end, atomic<unsigned long long>& sum)
{
	for (unsigned i = i_start; i < i_end; i++)
	{
		//std::lock_guard lock(mtx);
		mtx.lock();
		sum = v0[i] + v1[i];
		mtx.unlock();
	}
}


int main()
{
	const long long n_data = 100'100'100;
	const unsigned n_threads = 4;

	std::vector<int> v0, v1;
	v0.reserve(n_data);
	v1.reserve(n_data);

	random_device seed;
	mt19937 enfine(seed());

	unsigned long long sum = 0;

	uniform_int_distribution<> uniformDist(1, 10);

	for (long long i = 0; i < n_data; i++)
	{
		v0.push_back(uniformDist(enfine));
		v1.push_back(uniformDist(enfine));
	}

	std::cout << "std::inner_product" << std::endl;
	{
		const auto sta = chrono::steady_clock::now();

		const  auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	cout << "Naive" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;
		for (unsigned t = 0; t < n_threads; ++t)
		{
			threads[t] = std::thread(dotProductNaive, std::ref(v0), std::ref(v1), t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
		}
		for (unsigned t = 0; t < n_threads; ++t)
		{
			threads[t].join();
		}
		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		std::cout << sum << std::endl;

	}

	std::cout << "lock grode" << std::endl;
	{
		const auto sta = chrono::steady_clock::now();

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;
		for (unsigned t = 0; t < n_threads; ++t)
		{
			threads[t] = std::thread(dotProductNaiveLock, std::ref(v0), std::ref(v1), t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
		}
		for (unsigned t = 0; t < n_threads; ++t)
		{
			threads[t].join();
		}
		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		std::cout << sum << std::endl;

	}

	{
		const auto sta = chrono::steady_clock::now();

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;
		for (unsigned t = 0; t < n_threads; ++t)
		{
			threads[t] = std::thread(dotProductNaiveAt, std::ref(v0), std::ref(v1), t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
		}
		for (unsigned t = 0; t < n_threads; ++t)
		{
			threads[t].join();
		}
		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		std::cout << sum << std::endl;
	}

	std::cout << "std::transform_reduce" << std::endl;
	{
		const auto sta = chrono::steady_clock::now();

		const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		std::cout << sum << std::endl;
	}
}