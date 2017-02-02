//Accelerated C++
//Chapter 2 Looping and counting
//Question 2-3

#include <iostream>
#include <string>

using std::cin;		using std::endl;
using std::cout;	using std::string;

int main()
{
	cout << "Please enter your first name:";

	string name;
	cin >> name;
	
	const string greeting = "Hello, " + name + "!";

	cout << "Please enter your row padding:";

	int row_pad;
	cin >> row_pad;

	const int rows = row_pad * 2 + 3;

	cout << "Please enter your column padding:";


	int cols_pad;
	cin >> cols_pad;

	const string::size_type cols = greeting.size() + cols_pad * 2 + 2;

	cout << endl;

	for (int r = 0; r != rows; r++)
	{
		string::size_type c = 0;		

		while( c != cols) {
			if (r == row_pad + 1 && c == cols_pad+1){
				cout << greeting;
				c +=greeting.size();
			
			}
			else {
				if(r==0 || r == rows-1 || c == 0 || c==cols-1)
					cout <<"*";
				else
					cout <<" ";
				++c;
			}
		}
		cout << endl;

		}

	return 0;
}

//Answer::Introduced cins for the row padding and column padding