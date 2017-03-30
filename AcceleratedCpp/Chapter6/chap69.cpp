#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using std::vector; using std::string;	using std::cout;	using std::endl; using std::accumulate;

int main()
{
	typedef vector<int>::iterator vi_iter;
	
	vector<string> a;

	a.push_back("this ");
	a.push_back("is ");
	a.push_back("a ");
	a.push_back("test ");



	string b = accumulate(a.begin(),a.end(),string(""));

	cout << b << endl;



	return 0;

}