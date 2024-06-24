#include<iostream>
#include<array>

using namespace std;

template<typename T>

class Storage
{
private:
	T m_value;

public:
	Storage(T value): m_value(value){}

	void print() const
	{
		std::cout << "Stored value: " << m_value << std::endl;
	}
};


template<>
class Storage<const char*>
{
private:
	char* m_value;
public:
	Storage(const char* value)
	{
		size_t length = strlen(value) + 1;
		m_value = new char[length];
		strcpy_s(m_value, length,value);
	}

	~Storage()
	{
		delete[] m_value;
	}

	void print() const
	{
		std::cout << "Stored string: " << m_value << std::endl;
	}
};

int main()
{
	Storage<int> intStorage(123);
	intStorage.print(); // �Ϲ� ���ø� Ŭ���� ���

	Storage<const char*> stringStorage("Hello, World!");
	stringStorage.print(); // Ư��ȭ�� ���ø� Ŭ���� ���

	return 0;
}