//Accelerated C++
//Chapter 6 Using library algorithms
//Question 6-3

#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;	using std::cout;	using std::endl;



int main()
{

	vector<int> u(10,100);

	//this will compile but throw a Segmentation Fault because there is no element at v.begin()
	vector<int> v;
	copy(u.begin(),u.end(),v.begin());




	return 0;
}
