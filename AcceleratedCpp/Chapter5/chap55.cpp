//Accelerated C++
//Chapter 5 Using sequential containers and analyzing strings
//Question 5-5 

#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	//invariant: we have processed characters [original value of i ,i)
	while(i != s.size()){
		//ignore leading blanks
		//invariant : characters in range [ original i, current i) are all spaces
		while ( i != s.size() && isspace(s[i]))
		 ++i;

		//find of next word
		string_size j = i;
		//invariant: none of the characters in range [original j, current j) is a space
		while( j != s.size() && !isspace(s[j]))
			j++;
				// if we found some nonwhitespace characters
				if (i != j) {
					 // copy from s starting at i and taking j-i chars
					 ret.push_back(s.substr(i,j-i));
					 i = j;
				}


		}
	return ret;


}

string::size_type width(const vector<string>&v){
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); ++i){
		maxlen = max(maxlen,v[i].size());
	}
	return maxlen;
}

vector<string> center(const vector<string>& v){
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');

	//write the top border
	ret.push_back(border);

	//write each interior row, bordered by an asterisk and a space
	for( vector<string>::size_type i = 0; i != v.size(); ++ i )
	{
		if(v[i].size() % 2 == 0)
			ret.push_back( "* " + string((maxlen - v[i].size())/2, ' ') + v[i] + string((maxlen - v[i].size())/2, ' ') + " *");
		else
			ret.push_back( "* " + string((maxlen - v[i].size())/2, ' ') + v[i] + string((maxlen - v[i].size())/2+1, ' ') + " *");
	}

	//write the bottom border
	ret.push_back(border);
	return ret;
}





int main()
{


	string test = "This is my test string ueven";
	vector<string> result;
	result = split(test);

	cout << result.size() << endl;

	vector<string> centerpiece = center(result);
	vector<string>::iterator iter = centerpiece.begin();


	while(iter != centerpiece.end()){
		cout << *iter << endl;
		iter++;
	}



	return 0;
}