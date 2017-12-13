//Accelerated C++
//Chapter 12 Making class objects act like values
//Question 12-4

#include <algorithm>
#include <iostream>
#include <string>
#include <memory>
#include <cstddef>
#include <cstring>


using std::allocator;

using std::max;

class Str{
	friend std::istream& operator>>(std::istream&, Str&);

public:
	typedef char* iterator;
	typedef const char* const_iterator;
	typedef size_t size_type;
	typedef char value_type;
	typedef char& reference;
	typedef const char& const_reference;


	Str& operator+=(const Str& s){
		//std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
		return *this;
	}

	//as before
	Str() { create();}
	//Str(size_type n, char c): data(n,c) {}
	explicit Str(size_type n, const char& t = char()) { create(n,t);}
	Str(const Str& s){create(s.begin(),s.end());}

	Str(const char * cp) { create(cp,cp+strlen(cp));}

	~Str(){uncreate();}
	/*
		Vec(){create();}
		explicit Vec(size_type n, const T& t = T()) { create(n,t);}

		Vec(const Vec& v) {create(v.begin(),v.end());}
		Vec& operator=(const Vec&); //as defined in 11.3.2/196
		~Vec() {uncreate();}
	template <class In> Str(In b, In e){
		std::copy(b,e,std::back_inserter(data));
	}*/

	void push_back(const char& t){
		if (avail == limit)
			grow();
		unchecked_append(t);
	}

	size_type size() const { return avail - data;}

	iterator begin() {return data;}
	const_iterator begin() const { return data;}

	iterator end(){ return avail;}
	const_iterator end() const { return avail;}

	char& operator[](int i){ return data[i]; }
	const char& operator[](int i) const{ return data[i];}
	//int size() const { return length; }

private:
	char* data;
	int length;

	char* avail;
	char* limit;


	//iterator data; 	//first element in the Vec
	//iterator avail; //(one past) the last element in the Vec
	//iterator limit; //(one past) the allocated memory

	allocator<char> alloc; 

	//facilities for memory allocation
	//allocator<T> alloc;	//object to handle memory allocation
	void create();
	void create(size_type, const char&);
	void create(const_iterator, const_iterator);

		//destroy the elements in the array and free the memory
		void uncreate();

			//support functions for push_back
	void grow();
	void unchecked_append(const char&);
};

int operator<(Str &s,Str &t)
{
	return strcmp(s.begin(),t.begin()) < 0;
}

int operator>(Str &s,Str &t)
{
	return strcmp(s.begin(),t.begin()) > 0;
}

int operator==(Str &s,Str &t)
{
	return strcmp(s.begin(),t.begin()) == 0;
}

int operator!=(Str &s,Str &t)
{
	return strcmp(s.begin(),t.begin()) != 0;
}

int operator>=(Str &s,Str &t)
{
	return strcmp(s.begin(),t.begin()) >= 0;
}

int operator<=(Str &s,Str &t)
{
	return strcmp(s.begin(),t.begin()) <= 0;
}

std::istream& operator>>(std::istream& is, Str& s)
{
	//obliterate existing values 
	s.data=0;

	//read and discard leading whitespace 
	char c;
	while (is.get(c) && isspace(c))
		; // nothing to do, except testing the condition

	if (is){
		do s.push_back(c);  // would fail to compile without friend declaration
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

void Str::create()
{
	data = avail = limit = 0;
}

void Str::create(size_type n, const char& val)
{
	data = alloc.allocate(n);
	limit = avail = data+n;
	std::uninitialized_fill(data,limit,val);
}



void Str::create(const_iterator i , const_iterator j)
{
	data = alloc.allocate(j-i);
	limit = avail = std::uninitialized_copy(i,j,data);
}

void Str::uncreate()
{
	if(data){
		//destory (in reverse order ) the elements that were constructed
		iterator it = avail;
		while(it != data)
			alloc.destroy(--it);

		//return all the space that was allocated
		alloc.deallocate(data, limit-data);
	}
	//reset pointer to indcate that the Vec is empty again
	data = limit = avail = 0;
}

void Str::grow()
{
	//when growing allocate twice as much as currently in use
	size_type new_size = max(2 * (limit-data), ptrdiff_t(1));

	//allocate new space and copy existing elements to the new space
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data,avail,new_data);

	//return the old space
	uncreate();

	//reset pointers to point to the newly allocate space
	data = new_data;
	avail = new_avail;
	limit = data+new_size;
}

//assumes availa points at allocated, but uninitialized space 
void Str::unchecked_append(const char& val)
{
	alloc.construct(avail++,val);
}


/*
Str operator+(const Str& s, const Str& t)
{
	Str r = s;
	r += t;
	return r;
}*/