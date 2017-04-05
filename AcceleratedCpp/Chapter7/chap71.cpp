//Accelerated C++
//Chapter 7 Using associative containers
//Question 7-1



#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using std::cin;		using std::cout;		using std::endl;	
using std::map;		using std::string;		using std::vector;
using std::istream;	


int main()
{
	string s;
	map<string,int> counters; //store each word and an associated counter

	map<int, vector<string> > sorted_counters;

	//read the input, keeping track of each word and how often we see it
	while(cin >> s)
		++counters[s];

	//for the words and associated counts
	for(map<string,int>::const_iterator it = counters.begin(); it !=counters.end(); ++it)
	{
		sorted_counters[it->second].push_back(it->first);
		//cout << it->first <<"\t" << it->second << endl;
	}

	for(map<int, vector<string> >::iterator vit = sorted_counters.begin();vit != sorted_counters.end(); ++vit)
	{
		cout << vit->first <<": " ;
		for(vector<string>::iterator it = vit->second.begin();it!=vit->second.end();++it)
		{
			cout  << " " << *it ;
		}
		cout << endl;
	}




	return 0;
}