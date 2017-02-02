//Accelerated C++
//Chapter 2 Looping and counting
//Question 2-5
#include <iostream>

using namespace std;

int main()
{
	
	int input;
	cout << "Please enter 1) for Square 2) for Rectangle 3) for Triangle" << endl;
	cin >> input;

	if (input > 4 && input < 1)
	{
		cout << "Please run again with valid input";
		return 1;
	}

	int size;
	cout << "Please enter size" << endl;
	cin >> size;

	if (input == 1)
	{

		for (int i = 0 ; i < size; i++)
		{
			for(int j = 0; j <size; j++)
			{
				cout << "*" ;
			}
			cout << endl;
		}
	}
	else if (input == 2)
	{

		for (int i = 0 ; i < size/2; i++)
		{
			for(int j = 0; j <size; j++)
			{
				cout << "*" ;
			}
			cout << endl;
		}

	}

	else if (input == 3)
	{
		if (size % 2 == 0)
			size++;

		size_t mid = 1;
		size_t pad = (size_t)size/2;
		for(int i = 0; i < size/2+1;i++)
		{
			cout << string(pad,' ') << string(mid,'*') << string(pad,' ') << endl;
			pad--;
			mid = mid + (size_t)2;
		}
	}





	return 0;
}

//Answer: Ask for input and size and use basic geometry to output the shapes.