#include<iostream>

class A
{
public:
	virtual void print() { std::cout << "A" << std::endl; }
};

class B : public A
{
public:
	void print() { std::cout << "B" << std::endl; }
};


class C : public B
{
public:
	void print() { std::cout << "C" << std::endl; }
};


class D : public C
{
public:
	void print() { std::cout << "D" << std::endl; }
};

int main()
{
	A a;
	B b;
	C c;
	D d;

	A& ref = b;
	ref.print();
}