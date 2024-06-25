#include<iostream>

using namespace std;

int fac(int n)
{
	if (n == 0 || n == 1) return 1;
	return n * fac(n - 1);
}

int fibo(int n) {
	//cout << " " << endl;
	if (n == 0 || n == 1) return n;
	return  fibo(n - 1) + fibo(n - 2);
}



int main()
{
	int a = fac(5);
	std::cout << "a: " << a << endl;
}