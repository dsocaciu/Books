//Accelerated C++
//Chapter 4 Organizing programs and data
//Question 4-2

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	for(int i = 0; i <= 100; i++)
	{
		cout <<setw(3) << i << setw(6) << i*i << endl;
	}

	return 0;
}