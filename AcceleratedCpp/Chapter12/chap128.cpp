//Accelerated C++
//Chapter 12 Making class objects act like values
//Question 12-8

#include <iostream>
#include "Str128.h"

using std::cout;	using std::endl;

int main()
{

	Str s;

	cout << "Enter a line" << endl;

	getline(std::cin,s);

	cout << s << endl;



	return 0;
}