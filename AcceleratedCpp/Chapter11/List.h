#include <memory>
#include <cstddef>


using std::allocator;	

template<class T> class list{
		template <class U> friend size_t length(const list<U>&);
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef size_t size_type;
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;

		list(){create();}
		
		list(const_iterator b , const_iterator e) {
			data = alloc.allocate(e-b);
			std::uninitialized_copy(b,e,data);
		}
		list(const list& v) {create(v.begin(),v.end());}
		list& operator=(const list&);
		~list() {uncreate();}
		

		size_type size() const { return avail - data;}

		iterator begin() {return data;}
		const_iterator begin() const { return data;}

		iterator end(){ return avail;}
		const_iterator end() const { return avail;}

		void clear(){uncreate();}


	private:
		iterator data; 	//first element in the list
		iterator avail; //(one past) the last element in the list


		//facilities for memory allocation
		allocator<T> alloc;	//object to handle memory allocation

		//allocate and initialize the underlying array
		void create();
		void create(const_iterator, const_iterator);

		//destroy the elements in the array and free the memory
		void uncreate();

};