#include <iostream>
#include <cstring>
#include "Str122.h"

using std::cout;	using std::endl;

int main()
{

	Str s = "abc";

	cout << s.size() << endl;

	cout << s._data() << endl;

	cout << s.size() << endl;

	
}