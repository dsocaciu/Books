//Accelerated C++
//Chapter 6 Using library algorithms
//Question 6-2



#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using std::string;	using std::vector;	using std::cout;	using std::endl;

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

bool is_palindrome(const string& s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}

bool not_url_char(char c)
{
	//characters, in addition to alphanumerics, that can appear in a URL
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";

	//see whether c can appear in a URL and return the negative
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end() , c) != url_ch.end());
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
	return find_if(b,e,not_url_char);
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "://";

	typedef string::const_iterator iter;

	//i marks where the separator was found
	iter i = b;

	while ((i = search(i,e ,sep.begin(), sep.end())) != e)
	{

		//make sure the separator isn't at the beginning or end of the line
		if ( i != b && i + sep.size() != e)
		{
			//beg marks teh beginning of the protocol name
			iter beg = i;
			while (beg!= b && isalpha(beg[-1]))
				--beg;

			//is there at least one appropriate character before and after the separator?
			if (beg != i && !not_url_char(i[sep.size()]))
				return beg;
		}

		// the separator we found wasn't part of a URL; advance i past this separator
		i += sep.size();
	}
	return e;
}

vector<string> find_urls(const string& s)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e =s.end();

	//look through the entire input
	while ( b != e)
	{

		//look for one or more letters followed by ://
		b = url_beg(b,e);

		//if we found it
		if( b != e){
			//get the rest of the URL
			iter after = url_end(b,e);

			// remember the URL
			ret.push_back(string(b,after));

			// advance b and check for more URLs on this line
			b = after;
		}
	}

	return ret;

}



int main()
{

	const string test1 = "http://www.AcceleratedCpp.com";

	vector<string> urls1 = find_urls(test1);
	cout << urls1.size() << endl;

	const string test2 = "http://www.AcceleratedCpp.com http://www.AcceleratedCpp.com http://www.AcceleratedCpp.com";

	vector<string> urls2 = find_urls(test2);
	cout << urls2.size() << endl;

	const string test3 = "http:/www.AcceleratedCpp.com http//www.AcceleratedCpp.com http://www.AcceleratedCpp.com";

	vector<string> urls3 = find_urls(test3);
	cout << urls3.size() << endl;

	return 0;
}
