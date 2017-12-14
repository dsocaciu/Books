//Accelerated C++
//Chapter 12 Making class objects act like values
//Question 12-5

#include <iostream>
#include "Str125.h"

using std::cout;	using std::endl;

int main()
{

	Str s = "abc";

	Str s2 = "def";

	Str s3 = s+s2;

	cout << s3 << endl;



	return 0;
}