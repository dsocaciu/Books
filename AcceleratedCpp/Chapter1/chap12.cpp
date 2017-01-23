//Accelerated C++
//Chapter 1 Working with strings
//Question 1-2
#include <iostream>

using namespace std;

int main(){

	const string exclam = "!";
	const string message = "Hello"+ ", world" + exclam;
	cout << message << endl;
	return 0;
}


/*Answer: This results in a compliation error because the string literal does
not support concatenation
*/