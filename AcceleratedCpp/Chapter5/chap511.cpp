//Accelerated C++
//Chapter 5 Using sequential containers and analyzing strings
//Question 5-11



#include <iostream>
#include <vector> 
#include "processing.h"

using std::endl; using std::cout; using std::vector;

int main()
{

	const string test1 = "abcd";
	const string test2 ="vcm";
	const string test3 = "uuuuuuuu";
	const string test4="pqls";

	vector<string> string_holder;

	string_holder.push_back(test1);
	string_holder.push_back(test2);
	string_holder.push_back(test3);
	string_holder.push_back(test4);

	vector<string>::iterator iter = string_holder.begin();

	string::size_type max = 0;

	while(iter!=string_holder.end())
	{
		if(!hasAscender(*iter) && !hasDescender(*iter))
		{
			if (max < iter->size())
				max = iter->size();
		}
		iter++;
	}


	cout << max << endl;

	//small initial test
	//cout << hasAscender(test1) << endl;
	//cout << hasAscender(test2) << endl;



	return 0;

}