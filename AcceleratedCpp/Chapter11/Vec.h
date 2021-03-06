#include <memory>
#include <cstddef>

using std::allocator;

template <class T> class Vec{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef size_t size_type;
		typedef T value_type;

		Vec(){create();}
		explicit Vec(size_type n, const T& t = T()) { create(n,t);}

		Vec(const Vec& v) {create(v.begin(),v.end());}
		Vec& operator=(const Vec&); //as defined in 11.3.2/196
		~Vec() {uncreate();}

		T& operator[](size_type i){ return data[i];}
		const T& operator[](size_type i) const { return data[i];}

		void push_back(const T& t){
			if (avail == limit)
				grow();
			unchecked_append(t);
		}

		size_type size() const { return avail - data;}

		iterator begin() {return data;}
		const_iterator begin() const { return data;}

		iterator end(){ return avail;}
		const_iterator end() const { return avail;}

	private:
		iterator data; 	//first element in the Vec
		iterator avail; //(one past) the last element in the Vec
		iterator limit; //(one past) the allocated memory

		//facilities for memory allocation
		allocator<T> alloc;	//object to handle memory allocation

		//allocate and initialize the underlying array
		void create();
		void create(size_type, const T&);
		void create(const_iterator, const_iterator);

		//destroy the elements in teh array and free the memory
		void uncreate();

		//support functions for push_back
		void grow();
		void unchecked_append(const T&);
};