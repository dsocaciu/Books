//Accelerated C++
//Chapter 1 Working with strings
//Question 1-6
#include <iostream>
#include <string>

int main()
{
	std::cout << "What is your name? ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name
			  << std::endl << "And what is yours? ";
	std::cin >> name;
	std::cout << "Hello, " << name
			  << "; nice to meet you too!" << std::endl;
	return 0;
}

/*Answer: 

What is your name? Samuel
Hello, Samuel
And what is yours? Beckeet
Hello, Beckeet; nice to meet you too!


What is your name? Samuel Beckett
Hello, Samuel
And what is yours? Hello, Beckett; nice to meet you too!

*/