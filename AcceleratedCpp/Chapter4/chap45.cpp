//Accelerated C++
//Chapter 4 Organizing programs and data
//Question 4-4

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;



int main()
{

	string word;
	vector<string> words;


	while(cin >> word){
		words.push_back(word);
	}

	cout << words.size() << endl;

	struct wordCount{
		string distinct_word;
		int count;
	};


	//calculate each word count
	//this is brute force and would be made more efficient by hashmap but the book hasn't touched upon those yet

	vector<wordCount> wordCounts;

	for (int i = 0; i < words.size(); i++ )
	{
		bool inTotalCount = false;
		int pos = 0;

		if (wordCounts.size() == 0)
		{
			wordCount temp;
			temp.distinct_word = words[i];
			temp.count = 1;
			wordCounts.push_back(temp);
		}
		else{
			for ( int j = 0; j < wordCounts.size() ; j++){
				if(words[i] == wordCounts[j].distinct_word){
					inTotalCount = true;
					pos = j;
				}
			}
			if(inTotalCount){
					wordCounts[pos].count++;
			}
			else{
				wordCount temp;
				temp.distinct_word = words[i];
				temp.count = 1;
				wordCounts.push_back(temp);
			}
		}
		
	}

	for (int i = 0 ; i < wordCounts.size(); i++){
		cout << wordCounts[i].distinct_word << " " << wordCounts[i].count << endl;
	}

	return 0;
}