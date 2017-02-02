//Accelerated C++
//Chapter 2 Looping and counting
//Question 2-1

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

	const int pad = 1;

	const int rows = 3;
	const string::size_type cols = greeting.size() + pad * 2;

	cout << endl;

	for (int r = 0; r != rows; r++)
	{
		string::size_type c = 0;		

		while( c != cols) {
			if (r==pad && c ==pad){
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

//Answer: Changes the rows variable,remove the additional padding from cols

