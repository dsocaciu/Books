//Accelerated C++
//Chapter 11 Defining abstract data types
//Question 11-7

#include <string>
#include <cctype>
#include <iostream>
#include "Vec116.cpp"

using namespace std;	

Vec<string> split(const string& s)
{
	Vec<string> ret;
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

string::size_type width(const Vec<string>&v){
	string::size_type maxlen = 0;
	for (Vec<string>::size_type i = 0; i != v.size(); ++i){
		maxlen = max(maxlen,v[i].size());
	}
	return maxlen;
}

Vec<string> frame(const Vec<string>& v){
	Vec<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');

	//write the top border
	ret.push_back(border);

	//write each interior row, bordered by an asterisk and a space
	for( Vec<string>::size_type i = 0; i != v.size(); ++ i )
	{
		ret.push_back( "* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
	}

	//write the bottom border
	ret.push_back(border);
	return ret;
}


Vec<string> vcat(const Vec<string>& top, const Vec<string>& bottom)
{
	//copy the top picture
	Vec<string> ret = top;

	//copy the entire bottom picutre
	for (Vec<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
		ret.push_back(*it);
		//could write the below comment instead
		//ret.insert(ret.end(),bottom.begin(),bottom.end());
	return ret;
}

Vec<string> hcat(const Vec<string>& left, const Vec<string>& right){
	Vec<string> ret;

	//add 1 to leave a space between pictures
	string::size_type width1 = width(left) + 1;

	//indices to look at elements from left and right respectively
	Vec<string>::size_type i = 0, j = 0;

	//continue until we've seen all rows from both pictures
	while( i != left.size() || j != right.size()){
		//construct new string to hold characters from both pictures
		string s;

		//copy a row from the left-hand side, if there is one
		if (i != left.size())
			s = left[i++];

		//pad to full width
		s += string(width1 - s.size(), ' ');

		if ( j != right.size())
			s += right[j++];

		//add s to the picture we're creating
		ret.push_back(s);


	}


	return ret;

}


int main()
{


	string test = "This is my test string";
	Vec<string> result;

	result = split(test);

	cout << result.size() << endl;

	Vec<string> frame_result = frame(result);
	Vec<string>::iterator iter = frame_result.begin();

	while(iter != frame_result.end())
	{
		cout << *iter << endl;
		iter++;
	}

	cout << endl << endl;

	Vec<string> v_result = vcat(result,frame(result));
	Vec<string>::iterator v_iter = v_result.begin();
	while(v_iter != v_result.end())
	{
		cout << *v_iter << endl;
		v_iter++;
	}

	cout << endl << endl;

	Vec<string> h_result = hcat(result,frame(result));
	Vec<string>::iterator h_iter = h_result.begin();
	while(h_iter != h_result.end())
	{
		cout << *h_iter << endl;
		h_iter++;
	}

	return 0;
}
/*
Chapter11 $ g++ Vec116.cpp  chap117.cpp -o chap117.o
Chapter11 $ ./chap117.o 
5
**********
* This   *
* is     *
* my     *
* test   *
* string *
**********


This
is
my
test
string
**********
* This   *
* is     *
* my     *
* test   *
* string *
**********


This   **********
is     * This   *
my     * is     *
test   * my     *
string * test   *
       * string *
       **********

       */