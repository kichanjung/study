#pragma once
#include<assert.h>
#include<iostream>

template<typename T, unsigned int T_SIZE>
class MyArray
{
private:
	//int m_length;
	T* m_data;

public:
	MyArray()
	{
		m_data = new T[T_SIZE];
	}

	void reset()
	{
		delete[] m_data;
		m_data = nullptr;
		T_SIZE = 0;
	}

	T& operator[] (int index)
	{
		//assert(index > = 0 && index < m_length);
		return m_data[index];
	}

	int getLength()
	{
		return T_SIZE;
	}

	void print()
	{
		for (int i = 0; i < T_SIZE; i++)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}
};