#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using std::cout;	using std::endl;	using std::vector;	using std::domain_error;	using std::sort;

template <class T>
T vec_median(vector<T> v)
{
	typedef typename vector<T>::size_type vec_sz;

	vec_sz size = v.size();

	if (size == 0)
		throw domain_error("median of an empty array");

	sort(v.begin(),v.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (v[mid]+v[mid-1])/2 : v[mid];

}

template <class T, class Iterator>
T median(Iterator start, Iterator end)
{

	vector<T> t_vec;

	while (start != end)
	{
		t_vec.push_back(*start);
		++start;
	}

	//for (size_t i = 0; i < N ; ++i)
	//	cout << start[i] << " ";
	//cout << endl;

	sort(t_vec.begin(),t_vec.end());



	size_t mid = t_vec.size()/2;

	T ret = (t_vec.size() % 2 == 0)? (t_vec[mid]+t_vec[mid-1])/2 : t_vec[mid];


	return ret;

}



int main()
{
	
	vector<int> test_vec;
	test_vec.push_back(1);
	test_vec.push_back(2);
	test_vec.push_back(3);

	//cout << vec_median(test_vec) << endl;

	static const int test_arr[] = {1,2,3};

	cout << sizeof(test_arr) << endl;
	cout << sizeof(*test_arr) << endl;

	size_t N = sizeof(test_arr)/sizeof(*test_arr);

	//median(test_arr,test_arr+N);

	median(test_vec.begin(),test_vec.end());


}