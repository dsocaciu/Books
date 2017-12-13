//Accelerated C++
//Chapter 11 Defining abstract data types
//Question 11-8

#include <algorithm>
#include "List.h"

using std::max;


template <class T> void list<T>::create()
{
	data = avail = 0;
}


template <class T>
void list<T>::create(const_iterator i , const_iterator j)
{
	data = alloc.allocate(j-i);
	avail = data + (j-i);
	std::uninitialized_copy(i,j,data);
}

template <class T> void list<T>::uncreate()
{
	if(data){
		//destory (in reverse order ) the elements that were constructed
		iterator it = avail;
		while(it != data)
			alloc.destroy(--it);

		//return all the space that was allocated
		alloc.deallocate(data, avail-data);
	}
	//reset pointer to indcate that the Vec is empty again
	data = avail = 0;
}

template <class T> list<T>& list<T>::operator=(const list<T>& other)
{
	if (this != other)
	{
		uncreate();
		data = alloc(other.data-other.avail);
		avail = data + (other.data-other.avail);
		uninitialized_copy(other.data,other.avail,data);
	}
}


template <class T> size_t length(const list<T>& l)
{
	return l.avail - l.data;
}

