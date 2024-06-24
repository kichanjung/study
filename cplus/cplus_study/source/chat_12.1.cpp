#include<iostream>
#include<string>


class Animal
{
protected:
	std::string m_name;

public:
	Animal(std::string name)
		:m_name(name)
	{}

public:
	std::string getName() { return m_name; }

	virtual void speak() const
	{
		std::cout << m_name << " ???" << std::endl;
	}

};

class Cat : public Animal
{
public:
	Cat(std::string name) : Animal(name)
	{}

	void speak() const
	{
		std::cout << m_name << " Meow" << std::endl;
	}
};

class Dog : public Animal
{
public:
	Dog(std::string name)
		: Animal(name)
	{}

	void speak() const
	{
		std::cout << m_name << " Woof" << std::endl;
	}
};

int main()
{
	Animal animal("my animal");
	Cat cat("my cat");
	Dog dog("my dog");

	animal.speak();
	cat.speak();

	Animal* ptr_animal1 = &cat;
	Animal* ptr_animal2 = &dog;

	ptr_animal1->speak();
	ptr_animal2->speak();

	Cat cats[] = { Cat("cat1"),Cat("cat2"),Cat("cat3"),Cat("cat4"),Cat("cat5") };

	Animal* my_animals[] = { &cats[0],&cats[1],&cats[2] };

	for (int i = 0; i < 3; i++) {
		my_animals[i]->speak();
	}
	return 0;
}
