//Accelerated C++
//Chapter 4 Organizing programs and data
//Question 4-3

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	for(int i = 0; i < 1000; i++)
	{
		cout <<setw(4) << i << setw(7) << i*i << endl;
	}

	return 0;
}