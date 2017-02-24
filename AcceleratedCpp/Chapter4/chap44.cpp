//Accelerated C++
//Chapter 4 Organizing programs and data
//Question 4-3

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;



int main()
{
	double logvar = log2(1000);
	cout << logvar << endl;
	for(double i = 0; i < 1000; i++)
	{
		cout <<setw(log2(i)) << i << setw(log2(i*i)) << i*i << endl;
	}

	return 0;
}