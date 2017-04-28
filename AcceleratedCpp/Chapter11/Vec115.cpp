//Accelerated C++
//Chapter 11 Defining abstract data types
//Question 11-5

#include "Vec115.h"

template<class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	//check for self-assignment
	if(&rhs != this)
	{
		//free the array in the left-hand side
		uncreate();

		//copy elements from the right-hand to the left-hand side
		create(rhs.begin(),rhs.end());
		assign_count++;
	}
}

template <class T> void Vec<T>::create()
{
	data = avail = limit = 0;
	create_count++;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data+n;
	uninitialized_fill(data,limit,val);
	create_count++;
}


template <class T>
void Vec<T>::create(const_iterator i , const_iterator j)
{
	data = alloc.allocate(j-i);
	limit = avail = uninitialized_copy(i,j,data);
	create_count++;
}

template <class T> void Vec<T>::uncreate()
{
	if(data){
		//destory (in reverse order ) the elements that were constructed
		iterator it = avail;
		while(it != data)
			alloc.destroy(--it);

		//return all the space that was allocated
		alloc.deallocated(data, limit-data);
		destroy_count++;
	}
	//reset pointer to indcate that the Vec is empty again
	data = limit = avail = 0;
}

template <class T> void Vec<T>::grow()
{
	//when growing allocate twice as much as currently in use
	size_type new_size = max(2 * (limit-data), ptrdiff_t(1));

	//allocate new space and copy existing elements to the new space
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = uninitialized_copy(data,avail,new_data);

	//return the old space
	uncreate();

	//reset pointers to point to the newly allocate space
	data = new_data;
	avail = new_avail;
	limit = data+new_size;
}

//assumes availa points at allocated, but uninitialized space 
template <class T> void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++,val);
}


