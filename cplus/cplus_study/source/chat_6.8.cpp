#include<iostream>
using namespace std;

void printArray(int array[])
{
	cout << sizeof(array) << endl;

	*array = 100;
}

int main()
{
	int array[5] = { 9,7,5,3,1 };

	cout << sizeof(array) << endl;

	int* ptr = array;

	printArray(ptr);

	cout << array[0] << endl;

}