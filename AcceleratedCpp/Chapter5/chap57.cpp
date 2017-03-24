//Accelerated C++
//Chapter 5 Using sequential containers and analyzing strings
//Question 5-7


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

vector<string> frame(const vector<string>& v){
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');

	//write the top border
	ret.push_back(border);

	//write each interior row, bordered by an asterisk and a space
	for( vector<string>::size_type i = 0; i != v.size(); ++ i )
	{
		ret.push_back( "* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
	}

	//write the bottom border
	ret.push_back(border);
	return ret;
}




int main()
{


	string test = "This is my test string";
	vector<string> result;
	result = split(test);

	cout << result.size() << endl;

	vector<string> frame_result = frame(result);
	vector<string>::iterator iter = frame_result.begin();

	while(iter != frame_result.end())
	{
		cout << *iter << endl;
		iter++;
	}

	cout << endl << endl;

	vector<string> v_result = vcat(result,frame(result));
	vector<string>::iterator v_iter = v_result.begin();
	while(v_iter != v_result.end())
	{
		cout << *v_iter << endl;
		v_iter++;
	}

	cout << endl << endl;

	vector<string> h_result = hcat(result,frame(result));
	vector<string>::iterator h_iter = h_result.begin();
	while(h_iter != h_result.end())
	{
		cout << *h_iter << endl;
		h_iter++;
	}

	return 0;
}

/*
Answer: There is a vector of strings (vector<string>) which is passed to both the width and frame functions
The width function determines the longest length of the strings in the vector.

Frame then computes the border as the width plus 4 additional units
In the body there is printed an asterisk, a space and then the word followed by the appropriate space and ending asterisk.

*/