//Accelerated C++
//Chapter 3 Working with batches of data
//Question 3-2

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
 

    int count = 0 ;
    double sum = 0.0;
 

    string x;
 

 	vector<string> words;
    vector<int> counts;

    while (cin >> x)
    {
        bool in = false;
        for(int i = 0 ; i < words.size();i++)
        {
            if(words[i] == x){
                counts[i]++;
                in = true;
            }

        }
        if(!in){
            words.push_back(x);
            counts.push_back(1);
        }
    }
 
    for (int i = 0; i < words.size();i++){
        cout << words[i] << " " << counts[i] << endl;
    }
 
}

/*Answer:
Example input and output
Enter all your homework grades, followed by end-of-file: 9 8 7 11 5 4 3 1
EOF
First Quartile
1 3 
Second Quartile
4 5 
Third Quartile
7 8 
Fourth Quartile
9 11 
*/