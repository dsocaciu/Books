//Accelerated C++
//Chapter 2 Looping and counting
//Question 2-9

#include <iostream>

using namespace std;

int main(){
	
	int first,second;

	cout << "Please enter first number " << endl;
	cin >> first;

	cout << "Please enter second number "<< endl;
	cin >> second;

	cout << "Larger number: ";
	if (first == second)
		cout << "doesn't exist; they're equal" << endl;
	if (first > second)
		cout << first <<endl;
	else
		cout << second << endl;


	return 0;

}

//Answer: Take in two integers from cin statements and run basic if else comparisons