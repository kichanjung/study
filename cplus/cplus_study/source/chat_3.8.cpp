#include<iostream>
#include<bitset>

int main()
{
	using namespace std;

	// << left shift
	// >> right shift
	// ~, &, |, ^ 

	/*unsigned int a = 3;
	
	cout << std::bitset<4>(a) << endl;

	unsigned int b =a << 3;

	cout << std::bitset<8>(b) <<" "<<b << endl;*/

	unsigned int a = 1024;

	cout << std::bitset<16>(a) << endl;

	cout << std::bitset<16>(~a) << " " << (~a) << endl;
	cout << std::bitset<16>(a>>2) << " " << (a>>2) << endl;
	cout << std::bitset<16>(a>>3) << " " << (a>>3) << endl;
	cout << std::bitset<16>(a>>4) << " " << (a>>4) << endl;
	cout << std::bitset<16>(a >> 5) << " " << (a >> 5) << endl;
	cout << std::bitset<16>(a >> 6) << " " << (a >> 6) << endl;
	cout << std::bitset<16>(a >> 7) << " " << (a >> 7) << endl;
	cout << std::bitset<16>(a >> 8) << " " << (a >> 8) << endl;
	cout << std::bitset<16>(a >> 9) << " " << (a >> 9) << endl;
	cout << std::bitset<16>(a >> 10) << " " << (a >> 10) << endl;
	cout << std::bitset<16>(a >> 11) << " " << (a >> 11) << endl;
	cout << std::bitset<16>(a >> 12) << " " << (a >> 12) << endl;

	return 0;
}