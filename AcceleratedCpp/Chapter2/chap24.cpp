//Accelerated C++
//Chapter 2 Looping and counting
//Question 2-4


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

	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	cout << endl;

	for (int r = 0; r != rows; r++)
	{
		string::size_type c = 0;		

		while( c != cols) {
			if (r==pad + 1 && c ==pad){
				cout << " " << greeting << " " ;
				c +=greeting.size();
				c +=2;
			
			}
			else {
				if(r==0 || r == rows-1 || c == 0 || c==cols-1)
				{
					cout <<"*";
					c++;
				}
				else
				{
					cout << string(greeting.size()+(string::size_type)2,' ');
					c=c+greeting.size()+2;
				}


				//++c;
			}
		}
		cout << endl;

		}

	return 0;
}

//Answer:: Use string constructor and length of the message to write the blank space. Modify the greeting line to 
//include the padsing
