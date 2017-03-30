//Accelerated C++
//Chapter 6 Using library algorithms
//Question 6-4

#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;	using std::cout;	using std::endl;

void printVector(vector<int>& vec)
{
	cout << "print vector" << endl;
	vector<int>::const_iterator iter = vec.begin();
	while(iter != vec.end())
	{
		cout << *iter<< endl;
		iter++;
	}
}

int main()
{

	vector<int> u(10,100);


	printVector(u);

	//this will compile but throw a Segmentation Fault because there is no element at v.begin()
	/*vector<int> v;
	copy(u.begin(),u.end(),v.begin());*/

	//first solution initalize with the allocated memory;
	vector<int> v (u.size(),10);

	copy(u.begin(),u.end(),v.begin());

	printVector(v);

	//second solution, use an iterator a la back_inserter
	vector<int> w;

	copy(u.begin(),u.end(),back_inserter(w));


	printVector(w);

	return 0;
}
