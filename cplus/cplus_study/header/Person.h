#pragma once
#include<string>
#include<iostream>

class Person
{
private:
	std::string n_name;
public:
	Person(const std::string& name_in = "No Name")
	{}

	void SetValue(const std::string& name_in)
	{
		n_name = name_in;
	}

	std::string GetValue()
	{
		return n_name;
	}
};