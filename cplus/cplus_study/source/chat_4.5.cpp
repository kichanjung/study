#include<iostream>
#include<limits>

int main()
{
	using namespace std;
	cout << 5u - 10u << std::endl;
	cout << (unsigned int)std::numeric_limits<unsigned int>::max() << endl;
}