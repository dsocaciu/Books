//Accelerated C++
//Chapter 12 Making class objects act like values
//Question 12-6

#include <iostream>
#include "Str126.h"

using std::cout;	using std::endl;

int main()
{

	Str s = "abc";

	Str s2 ;

	if (s.empty())
		cout << "s is empty" << endl;

	if (s2.empty())
		cout << "s2 is empty" << endl;



	return 0;
}