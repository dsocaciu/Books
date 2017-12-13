//Accelerated C++
//Chapter 12 Making class objects act like values
//Question 12-3

#include <iostream>
#include "Str123.h"

using std::cout;	using std::endl;

int main()
{

	Str s = "abc";

	Str t = "abc";

	cout << s.size() << endl;

	if (s < t)
	{
		cout << "s less than t" << endl;
	}
	else if( s > t)
	{
		cout << "s more than t" << endl;
	}
	else
	{
		cout << "s equals t" << endl;
	}

	return 0;
}