#include<iostream>

struct Person
{
	double height = 3.0;
	float weight = 200.0;
	int age= 100;
	std::string name="jung";

	void printPerson()
	{
		std::cout << height << " " << weight << " " << age << " " << name;
		std::cout << std::endl;
	}
};

struct Family
{
	Person me, mom, dad;
};

Person getMe()
{
	Person me{ 2.0, 100.0, 20, "Jack Jack" };
	return me;
}

struct Employee // 2 + (2) + 4 + 8
{
	char* a[3];
	short id;
	int age;
	double wage;
};

int main()
{
	//Person func_per = getMe();
	//func_per.printPerson();

	Employee emp1;
	std::cout << sizeof(emp1.a) << std::endl;
}