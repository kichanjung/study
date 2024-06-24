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

	virtual void speak() const = 0; //pure virtual function

	/*virtual void speak() const
	{
		std::cout << m_name << " ???" << std::endl;
	}*/

};

class Cat : public Animal
{
public:
	Cat(std::string name) : Animal(name)
	{}

	void speak() const override
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

	void speak() const override
	{
		std::cout << m_name << " Woof" << std::endl;
	}
};

class Cow : public Animal
{
public:
	Cow(std::string name)
		: Animal(name)
	{}
	void speak() const override
	{
		std::cout << m_name << " aa" << std::endl;
	}
};


class IErrorLog
{
public:
	virtual bool reportError(std::string error) =0;
};

class FileErrorLog: public IErrorLog
{
public:
	bool reportError(std::string error) override
	{
		std::cout << "Writing error " << std::endl;
		return true;
	}
	
};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(std::string error) override
	{
		std::cout << "Printing error " << std::endl;
		return true;
	}
};

void doSomething(IErrorLog& log)
{
	log.reportError("Runtime error!!!");
}

int main()
{
	//Animal animal("my animal");
	
	FileErrorLog file_log;
	file_log.reportError("aa");
	doSomething(file_log);

	return 0;
}
