//Accelerated C++
//Chapter 7 Using associative containers
//Question 7-0



#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using std::cin;		using std::cout;		using std::endl;	
using std::map;		using std::string;		using std::vector;
using std::istream;	using std::logic_error;	using std::domain_error;


bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}




vector<string> split (const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while ( i!=str.end()){

		//ignore leading blank
		i = find_if(i, str.end(), not_space);

		//find end of next word
		iter j = find_if(i, str.end(),space);

		//copy the characters in [i,j)
		if ( i != str.end())
			ret.push_back(string(i,j));
		i=j;
	}
	return ret;
}





int main()
{
	string s;
	map<string,int> counters; //store each word and an associated counter

	//read the input, keeping track of each word and how often we see it
	while(cin >> s)
		++counters[s];

	//for the words and associated counts
	for(map<string,int>::const_iterator it = counters.begin(); it !=counters.end(); ++it)
	{
		cout << it->first <<"\t" << it->second << endl;
	}






	return 0;
}