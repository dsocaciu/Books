//Accelerated C++
//Chapter 2 Looping and counting
//Question 2-8

#include <iostream>

int main(){
	
	int sum = 1;

	for (int i = 1; i < 10;i++)
	{
		sum *=i;
	}

	std::cout << sum << std::endl;

	return 0;
}


//Answer: Initalize an integer to 1 ( 1 times anything is anything) , multiply by the increasing amount until 10
