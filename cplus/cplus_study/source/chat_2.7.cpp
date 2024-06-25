#include<iostream>
#include<limits>

int main()
{
	using namespace std;
	//char c1(65);
	//char c2('A');

	//cout << c1 << " " << c2 << int(c1) << " " << int(c2) << endl;

	////C
	//cout << (char)65 << endl;
	//cout << (int)'A' << endl;

	//cout << char(65) << endl;
	//cout << int('A') << endl;

	//cout << static_cast<char>(65) << endl;
	//cout << static_cast<int>('A') << endl;

	//char ch(97);
	//cout << ch << endl;
	//cout << static_cast<int>(ch) << endl;
	//cout << ch << endl;

	cout << sizeof(char) << endl;
	cout << (long long)std::numeric_limits<long long>::max() << endl;
	cout << (long long)std::numeric_limits<long long>::lowest() << endl;
	
	return 0;
}