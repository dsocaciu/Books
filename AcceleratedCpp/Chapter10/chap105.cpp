//Accelerated C++
//Chapter 10 Managing memory and low-level data structures
//Question 10-5


#include <list>
#include <string>
#include <iostream>

using std::list;	using std::string;	using std::cout;	using std::endl;

class listOfStrings
{
	private:
		list<string> holder;
		list<string>::iterator holder_i;
	public:
		listOfStrings() {holder_i = holder.begin();}
		listOfStrings(list<string> hld){ holder = hld;}
		void addString(string str){
			holder.push_back(str);
		}
		list<string> getHolder()
		{
			return holder;
		}
		void setHolderI(list<string>::iterator iter)
		{
			holder_i = iter;
		}
		list<string>::iterator firstElement()
		{
			return holder.begin();
		}
		list<string>::iterator nextElement()
		{
			if (holder_i != holder.end())
			{
				holder_i++;
				return holder_i;
			}
			return holder.end();
		}
		list<string>::iterator previousElement()
		{
			if(holder_i != holder.begin())
			{
				holder_i--;
				return holder_i;
			}
			return holder.begin();
		}

};

int main()
{
	listOfStrings los;

	los.addString("test");
	los.addString("test2");

	list<string> test = los.getHolder();


	//for (list<string>::iterator i = test.begin(); i!=test.end(); i++)
	//{
	//	cout << *i << endl;
	//}

	list<string>::iterator i = los.firstElement();

	los.setHolderI(i);

	cout << *i << endl;



	i = los.nextElement();

	cout << *i << endl;

	i = los.previousElement();

	cout << *i << endl;


	return 0;
}
