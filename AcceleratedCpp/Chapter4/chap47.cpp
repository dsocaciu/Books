//Accelerated C++
//Chapter 4 Organizing programs and data
//Question 4-7

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector<double> homework;
	double average;


	homework.push_back(100);
	homework.push_back(97.2);
	homework.push_back(95.6);
	homework.push_back(96.4);
	homework.push_back(93.7);

	for (int i = 0; i < homework.size(); i++)
	{
		average += homework[i];
	}
	average = average/homework.size();

	cout << "Average: " << average << endl;
}