//Accelerated C++
//Chapter 3 Working with batches of data
//Question 3-4

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
 
int main()
{
 

    cout << "Enter all your words, "
            "followed by end-of-file: ";


    string input;

    int min = 1000;
    string min_string;
    int max = 0;
    string max_string;

    while ( cin >> input){

        string temp = input;

        if (temp.length() < min){
            min = temp.length();
            min_string = temp;

        }

        if( max < temp.length())
        {
            max = temp.length();
            max_string = temp;
        }

    }

    cout << "Min: " << min_string << min << endl;

    cout << "Max: " << max_string << max << endl;
 

    
}