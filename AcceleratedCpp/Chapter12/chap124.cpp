//Accelerated C++
//Chapter 12 Making class objects act like values
//Question 12-4

#include <iostream>
#include "Str124.h"

using std::cout;	using std::endl;

int main()
{

	Str s = "abc";

	Str s2 = "abd";

	Str t = "abd";

	cout << s.size() << endl;

	if (s <= t)
	{
		cout << "s less than or equal to t" << endl;
	}
	else if( s >= t)
	{
		cout << "s more than t" << endl;
	}


	if (s2 <= t)
	{
		cout << "s2 less than or equal to t" << endl;
	}
	else if( s2 >= t)
	{
		cout << "s2 more than t" << endl;
	}

	if (s != t)
	{
		cout << "s not equal to t" << endl;
	}


	if (s == t)
	{
		cout << "s equals t" << endl;
	}

	if (s2 != t)
	{
		cout << "s2 not equal to t" << endl;
	}


	if (s2 == t)
	{
		cout << "s2 equals t" << endl;
	}

	return 0;
}