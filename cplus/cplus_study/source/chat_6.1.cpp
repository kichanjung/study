#include<iostream>

struct Rectangle
{
	int length;
	int width;
};

enum StudentName
{
	JACKJACK,
	DASH,
	VIOLET,
};

int main()
{
	const int num_students = 20;

	int students_scores[num_students] = {1,2,3,4,5};

	std::cout << &students_scores << std::endl;
	std::cout << &(students_scores[0]) << std::endl;
	std::cout << &(students_scores[1]) << std::endl;
	std::cout << &(students_scores[2]) << std::endl;
	std::cout << &(students_scores[3]) << std::endl;
	std::cout << &(students_scores[4]) << std::endl;
	

	return 0;

}