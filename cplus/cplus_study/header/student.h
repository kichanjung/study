#pragma once


#include"person.h"

class Student : public Person
{
private:
	int m_intel;
public:
	Student(const std::string & name_in = "No Name", const int& intel_in =0)
		: Person(name_in), m_intel(intel_in)
	{}

	void study()
	{
		std::cout << GetValue() << std::endl;
	}
};