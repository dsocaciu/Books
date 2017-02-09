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
 

    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";
 

    int count = 0 ;
    double sum = 0.0;
 

    double x;
 

 	vector<double> grades;

    while (cin >> x)
    {
        ++count;
        sum += x;
        grades.push_back(x);

    }
 
 

    streamsize prec = cout.precision();
 

    //for ease of calculation assume all inputs are divisble by 4
    //otherwise additional logic is needed to determine the quartile size

    std::sort(grades.begin(),grades.end());

     int quart_size = grades.size()/4;

     cout << "First Quartile" << endl;
     for (int i = 0; i < quart_size;i++)
     {
     	cout << grades[i] << " ";
     }
     cout << endl;

     cout << "Second Quartile" << endl;
     for (int i = quart_size; i < quart_size*2;i++)
     {
     	cout << grades[i] << " ";
     }
     cout << endl;

	 cout << "Third Quartile" << endl;
     for (int i = quart_size*2; i < quart_size*3;i++)
     {
     	cout << grades[i] << " ";
     }
     cout << endl;   

     cout << "Fourth Quartile" << endl;
     for (int i = quart_size*3; i < quart_size*4;i++)
     {
     	cout << grades[i] << " ";
     }
     cout << endl;

 
    return 0;
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