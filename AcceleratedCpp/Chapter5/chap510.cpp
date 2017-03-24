//Accelerated C++
//Chapter 5 Using sequential containers and analyzing strings
//Question 5-10

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(const string& input)
{
	
	int i = 0;
	int j = input.size()-1;



	while(j > i )
	{
		if (input[i] != input[j])
			return false;
		i++;
		j--;

	}

	return true;

}

string::size_type longestPalindrome(vector<string> input_vec)
{
	vector<string>::iterator iter = input_vec.begin();
	string::size_type max_length = 0;
	while( iter != input_vec.end())
	{
		if(isPalindrome(*iter))
		{
			if (iter->size() > max_length)
				max_length = iter->size();
		}
		iter++;
	}

	return max_length;
}


int main()
{
	string test1 = "abcd";
	string test2 = "abba";
	string test3 = "abcba";
	
	cout << isPalindrome(test1) << endl;
	cout << isPalindrome(test2) << endl;
	cout << isPalindrome(test3) << endl;

	vector<string> inputs;
	inputs.push_back(test1);
	inputs.push_back(test2);
	inputs.push_back(test3);

	cout << longestPalindrome(inputs) << endl;

	return 0;
}