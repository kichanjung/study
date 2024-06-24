#include<iostream>

class Mother
{
private:
	int m_i;
public:
	Mother() : m_i(0)
	{

	};
	Mother(const int c): m_i(c)
	{

	}
	void setValue(const int& i)
	{
		m_i = i;
	}

	int getValue()
	{
		return m_i;
	}

};

class Child : public Mother
{
private:
	int m_c;
	double m_d;
public:
	Child(const int& c, const double& d) : Mother(c), m_c(c), m_d(d)
	{

	}
	void setValue(const double& d)
	{
		m_d = d;
	}
	double getValue()
	{
		return m_d;
	}
};

class Daughter : public Mother
{

};

class Son : public Mother
{

};

int main()
{
	Mother mother;
	Child child(48,1);
	child.getValue();
	std::cout << child.Mother::getValue() << std::endl;
}