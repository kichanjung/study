#pragma once
class Resource
{
public:
	int* m_data = nullptr;
	unsigned m_lenght = 0;

public:
	Resource()
	{
		std::cout << "Resource default constructed" << std::endl;
	}
	Resource(unsigned lenght)
	{
		std::cout << "Resource lenght constructed" << std::endl;
		this->m_data = new int[lenght];
		this->m_lenght = lenght;
	}
	Resource(const Resource& res)
	{
		std::cout << "Resource copy constructed" << std::endl;

		Resource(res.m_lenght);
		for (unsigned i = 0; i < m_lenght; i++)
			m_data[i] = res.m_data[i];
	}
	void print()
	{
		for (unsigned i = 0; i < m_lenght; i++)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}
	void setAll(const int& v)
	{
		for (unsigned i = 0; i < m_lenght; i++)
			m_data[i] = v;
;	}
};