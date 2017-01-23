//Accelerated C++
//Chapter 1 Working with strings
//Question 1-4
#include <iostream>
#include <string>

int main()
{
	{ const std::string s = "a string";
	  std::cout << s << std::endl;

	{ const std::string s = "another string";
	  std::cout << s << std::endl; }}	
	return 0;
}

/*Answer: This program is valid.

The ouput is :
"
a string
another string
"
*/