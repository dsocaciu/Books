//Accelerated C++
//Chapter 5 Using sequential containers and analyzing strings
//Question 5-9


#include <iostream>
#include <cctype>

using namespace std;

string toUpperString(string& input)
{
	for(int i = 0 ; i < input.size() ; i++)
	{
		input[i] = toupper(input[i]);
	}
	return input;
}

string toLowerString(string& input)
{
	for(int i = 0 ; i < input.size() ; i++)
	{
		input[i] = tolower(input[i]);
	}
	return input;
}

int main()
{
	
	string string1 = "teST1";
	string string2 = "test2";
	string string3 = "TEST3";
	string string4 = "TEst4";

	cout << toUpperString(string1) << " " << toLowerString(string1) << endl;
	cout << toUpperString(string2) << " " << toLowerString(string2) << endl;
	cout << toUpperString(string3) << " " << toLowerString(string3) << endl;
	cout << toUpperString(string4) << " " << toLowerString(string4) << endl;


}

//Can extend to take user input but this exercise to showcase toupper and tolower functions

