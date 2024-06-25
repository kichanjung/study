#include<iostream>
#include "chat_4.2.3.h"

using namespace std;

extern void doSomething();
extern int sharedVariable;

int main()
{
	/*cout << value << endl;
	int value = 1;
	cout << ::value << endl;
	cout << value << endl;*/

	std::cout << sharedVariable << std::endl;
	sharedVariable += 3;
	std::cout << sharedVariable << std::endl;
	std::cout << "4,1" << Constants::pi << " " << &Constants::pi << std::endl;

	doSomething();
	return 0;
}