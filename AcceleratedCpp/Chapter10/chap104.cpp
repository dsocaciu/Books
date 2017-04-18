#include <list>
#include <string>
#include <iostream>

using std::list;	using std::string;	using std::cout;	using std::endl;

class listOfStrings
{
	private:
		list<string> holder;
	public:
		listOfStrings() {

		}
		void addString(string str){
			holder.push_back(str);
		}
		list<string> getHolder()
		{
			return holder;
		}

};

int main()
{
	listOfStrings los;

	los.addString("test");

	list<string> test = los.getHolder();


	for (list<string>::iterator i = test.begin(); i!=test.end(); i++)
	{
		cout << *i << endl;
	}


	return 0;
}
