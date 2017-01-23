//Accelerated C++
//Chapter 1 Working with strings
//Question 1-3
#include <iostream>
#include <string>

int main()
{
	{ const std::string s = "a string";
	  std::cout << s << std::endl; }

	{ const std::string s = "another string";
	  std::cout << s << std::endl; }
	
	return 0;
}

/* Answer: The program is valid. 
It prints out:

"
a string
another string
"

*/