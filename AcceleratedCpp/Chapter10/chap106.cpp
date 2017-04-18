//Accelerated C++
//Chapter 10 Managing memory and low-level data structures
//Question 10-6


#include <list>
#include <string>
#include <iostream>

using std::list;	using std::string;	using std::cout;	using std::endl;


bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

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


listOfStrings split(const string& str)
{
	listOfStrings temp;
	typedef string::const_iterator iter;

	iter i = str.begin();
	while ( i != str.end()) {
		//ignore leading blanks
		i = find_if(i, str.end(), not_space);

		//find end of next word
		iter j = find_if(i, str.end(),space);

		//copy the characters in [i,j)
		if( i != str.end())
			temp.addString(string(i,j));	//changed

		i = j;
	}

	return temp;
}


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

	listOfStrings los2 = split("This is a list of strings");

	list<string> test2 = los2.getHolder();


	for (list<string>::iterator i = test2.begin(); i!=test2.end(); i++)
	{
		cout << *i << endl;
	}





	return 0;
}
