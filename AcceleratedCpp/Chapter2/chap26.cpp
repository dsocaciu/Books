//Accelerated C++
//Chapter 2 Looping and counting
//Question 2-6

#include <iostream>

int main()
{
	int i = 0;
	while( i < 10){
		i+=1;
		std::cout << i << std::endl;
	}
	return 0;
}

//Answer: Writes 1 to 10 sequentially  on separate lines
//Note the addition is before the cout line
