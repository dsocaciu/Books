//Accelerated C++
//Chapter 1 Working with strings
//Question 1-1

#include <iostream>

using namespace std;

int main(){

	const string hello = "Hello";
	const string message = hello + ",world" + "!";
	cout << message << endl;
	return 0;
}



/*Answer: The definitions are valid because the operators + are left associative
the string is able to concatenate the string literals
*/