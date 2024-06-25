#include<iostream>
#include "chat_4.2.3.h"

using namespace std;

extern int sharedVariable =42;

void doSomething()
{
	sharedVariable = 3;
	std::cout << "4,2" << Constants::pi << " " << &Constants::pi << std::endl;
}