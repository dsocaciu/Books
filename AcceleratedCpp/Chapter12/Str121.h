#include <algorithm>
#include <iostream>

class Str{
	friend std::istream& operator>>(std::istream&, Str&);

public:
	Str& operator+=(const Str& s){
		//std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
		return *this;
	}

	//as before
	Str() { }
	//Str(size_type n, char c): data(n,c) {}
	Str(char* cp){
		for( char* runner = cp;*cp;++cp)
		{
			++data = runner;
		}
	}
	/*
	template <class In> Str(In b, In e){
		std::copy(b,e,std::back_inserter(data));
	}*/

	char& operator[](int i){ return data[i]; }
	const char& operator[](int i) const{ return data[i];}
	int size() const { return length; }

private:
	char* data;
	int length;
};

std::istream& operator>>(std::istream& is, Str& s)
{
	//obliterate existing values 
	data=0;

	//read and discard leading whitespace 
	char c;
	while (is.get(c) && isspace(c))
		; // nothing to do, except testing the condition

	if (is){
		do ++&s.data = c;
		while (is.get(c) && !isspace(c));

		//if we read whitespace, then put it back on the stream
		if ( is )
			is.unget();
	}

	return is;

}

std::ostream& operator<<(std::ostream& os, const Str& s)
{
	for(int i = 0; i != s.size(); ++i)
		os << s[i];
	return os;
}


/*
Str operator+(const Str& s, const Str& t)
{
	Str r = s;
	r += t;
	return r;
}*/