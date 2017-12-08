#include <algorithm>
#include <iostream>
#include "Vec.cpp"

class Str{
	friend std::istream& operator>>(std::istream&, Str&);

public:
	Str& operator+=(const Str& s){
		std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
		return *this;
	}

	//as before
	typedef Vec<char>::size_type size_type;

	//default constructor; create an empty Str
	Str() { }

	//create a Str containing n copies of c
	Str(size_type n, char c): data(n,c) {}

	//create a Str from a null-termianted array of char
	Str(const char* cp){
		std::copy(cp,cp+std::strlen(cp), std::back_inserter(data));
	}

	//create a Str from the range denated by iterators b and e
	template <class In> Str(In b, In e){
		std::copy(b,e,std::back_inserter(data));
	}

	char& operator[](size_type i){ return data[i]; }
	const char& operator[](size_type i) const{ return data[i];}
	size_type size() const { return data.size(); }

	const char* c_str() { std::copy("",""+std::strlen(""), std::back_inserter(data)); return data.begin();}
	const char* _data() { return data.begin();}
	

private:
	Vec<char> data;
};

std::istream& operator>>(std::istream& is, Str& s)
{
	//obliterate existing values 
	s.data.clear();

	//read and discard leading whitespace 
	char c;
	while (is.get(c) && isspace(c))
		; // nothing to do, except testing the condition

	if (is){
		do s.data.push_back(c); // would fail to compile without friend declaration
		while (is.get(c) && !isspace(c));

		//if we read whitespace, then put it back on the stream
		if ( is )
			is.unget();
	}

	return is;

}

std::ostream& operator<<(std::ostream& os, const Str& s)
{
	for(Str::size_type i = 0; i != s.size(); ++i)
		os << s[i];
	return os;
}

Str operator+(const Str& s, const Str& t)
{
	Str r = s;
	r += t;
	return r;
}