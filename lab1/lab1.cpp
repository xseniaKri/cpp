#include <iostream>
#include <string>
#include <bitset>
using std::cin;
using std::cout;
using std::endl;
using std::bitset;
using std::hex;
int main()
{ 
	//Задание номер 1
	cout << "Kripak Ksenia Romanovna, 241-326" << endl;
	//Задание номер 2
	int min_int, max_int;
	min_int = 0b10000000000000000000000000000000;
	max_int = 0b01111111111111111111111111111111;
	cout << "min int = " << min_int << ", max int = " << max_int << ", size of int = " << sizeof(int) << endl;
	unsigned int min_unsigned_int, max_unsigned_int;
	min_unsigned_int = 0b00000000000000000000000000000000;
	max_unsigned_int = 0b11111111111111111111111111111111;
	cout << "min unsigned int = " << min_unsigned_int << ", max_unsigned_int = " << max_unsigned_int << ", size of unsigned int = " <<
		sizeof(unsigned int) << endl;
	short min_short, max_short;
	min_short = 0b1000000000000000;
	max_short = 0b0111111111111111;
	cout << "min short = " << min_short << ", max short = " << max_short << ", size of short = " << sizeof(short) << endl;
	unsigned short min_unsigned_short, max_unsigned_short;
	min_unsigned_short = 0b0000000000000000;
	max_unsigned_short = 0b1111111111111111;
	cout << "min unsigned short = " << min_unsigned_short << ", max unsigned short = " << max_unsigned_short <<
		", size of unsigned short = " << sizeof(unsigned short) << endl;
	long min_long, max_long;
	min_long = 0b10000000000000000000000000000000;
	max_long = 0b01111111111111111111111111111111;
	cout << "min long = " << min_long << ", max long = " << max_long << ", size of long = " << sizeof(long) << endl;
	long long min_long_long, max_long_long;
	min_long_long = 0b1000000000000000000000000000000000000000000000000000000000000000;
	max_long_long = 0b0111111111111111111111111111111111111111111111111111111111111111;
	cout << "min long long = " << min_long_long << ", max long long = " << max_long_long << ", size of long long = " << sizeof(long long) << endl;
	cout << "min double = " << -DBL_MAX << ", max double = " << DBL_MAX << ", size of double = " << sizeof(double) << endl;
	char min_char, max_char;
	min_char = 0b10000000;
	max_char = 0b01111111;
	cout << "min char = " << int(min_char) << ", max char = " << int(max_char) << ", size of char = " << sizeof(char) << endl;
	bool min_bool, max_bool;
	min_bool = 0b00000000;
	max_bool = 0b11111111;
	cout << "min bool = " << min_bool << ", max bool = " << max_bool << ", size of bool = " << sizeof(bool) << endl;
	//Задание номер 3
	cout << "Enter number: ";
	long int num;
	cin >> num;
	cout << "Your num in binary form: " << bitset<8 * sizeof(num)>(num) << endl;
	cout << "Your num in hexadecimal form: " << hex << num << endl;
	cout << "Your num in bool type: " << bool(num) << endl;
	cout << "Your num in double type: " << double(num) << endl;
	cout << "Your num in char type: " << char(num) << endl;
	//Задание номер 4
	cout << "Enter coefficients a and b, a * x = b: ";
	long int a, b;
	cin >> a >> b;
	cout << a << " * x = " << b << endl << "x = " << b << " / " << a << endl << "x = " << b / a << endl << "Answer: " 
		<< double(b) / double(a) << "." << endl;
	//Задание номер 5
	cout << "Enter the coordinates of the segment on the straight line: ";
	int x_1, x_2;
	cin >> x_1 >> x_2;
	cout << "The middle of the segment is located at the point with the coordinate " << double(x_1 + x_2) / 2 << "." << endl;
	return 0;
}