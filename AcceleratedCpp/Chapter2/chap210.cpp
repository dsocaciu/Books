//Accelerated C++
//Chapter 2 Looping and counting
//Question 2-10

#include <iostream>

int main()
{
	
	int k = 0;
	while ( k != 10 )
	{
		using std::cout;
		cout << "*";
		k++;
	}
	std::cout << std::endl;
	return 0;
}

//Answer: The first std:: is within the scope of the while loop. So the cout there doesn't require it additionally.
//The subsequent std::'s need to be declared 