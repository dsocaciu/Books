//Accelerated C++
//Chapter 2 Looping and counting
//Question 2-7

#include <iostream>

int main()
{
	int i = 10;
	while( i >-6 ){
		std::cout << i << std::endl;
		i--;
	}
	return 0;
}

//Answer:Similiar to 2-6, but flip the cout and the decrement function (in this case) and update the invariant