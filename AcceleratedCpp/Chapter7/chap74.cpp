//Accelerated C++
//Chapter 7 Using associative containers
//Question 7-4



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

//find all the lines that refer to each word in the input
map<string, vector<int> > xref(istream& in , vector<string> find_words(const string&) = split)
{
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;

	//read the next line
	while(getline(in,line)){
			++line_number;

		//break the input line into words
		vector<string> words = find_words(line);

		vector<int>::iterator vit;
		//remember that each word occurs on the current line
		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
		{
			vit = find (ret[*it].begin(),ret[*it].end(),line_number);
			if (vit == ret[*it].end())
				ret[*it].push_back(line_number);
		}

	}

	return ret;

}



int main()
{

	//call xref using split by default
	map<string, vector<int> > ret = xref(cin);
	int count = 0;

	//write the results
	for (map <string, vector<int> >::const_iterator it = ret.begin();it != ret.end(); ++it)
	{
		//write the word
		cout << it->first << " occurs on line(s): ";

		//followed by one or more line numbers
		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it; // write the first line numbers

		++line_it;

		while(line_it != it->second.end()){
			cout <<", " << *line_it;
			++line_it;
		}
		cout << "\t";

		//write a new line to separate each word from the next
		++count;


		if (count%3==0)
			cout << endl;
	}





	return 0;
}

//Admittedly a lazy solution to start a new line after each 3 words
//But it's a fairly open ended question