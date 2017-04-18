//Accelerated C++
//Chapter 10 Managing memory and low-level data structures
//Question 10-0

#include <iostream>

using std::cout;	using std::endl;


int main(int argc, char** argv)
{
	//if there are arguments, write them
	if(argc > 1)
	{
		int i;		//declare i outside the for because we need it after the loop finishes
		for ( i = 1; i < argc-1; ++i)	//write all but teh last entry 
			cout << argv[i] <<  " ";	//argv[i] is a char*

		cout << argv[i] << endl;		//write the last entry but not a space 
	}	
}