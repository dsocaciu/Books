//Accelerated C++
//Chapter 3 Working with batches of data
//Question 3-5


#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
 
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
 
int main()
{

    int numGrades; 
    vector<string> names;
    vector<double> grades;

    cout << "Please enter the number of grades" << endl;
    cin >> numGrades;

    cout << "Please enter your first name: ";
    
    string name;
    while (cin >> name){

        cout << "Please enter your grades:";


        double sum = 0.0;
        double x;
 
        for (int i = 0 ; i < numGrades; i++){
            cin >> x;
            sum+=x;

        }
        
        
        if(name != ""){
            names.push_back(name);
            grades.push_back(sum/numGrades);
            cout << "Please enter your first name: ";
        }


    }

    cout << endl;

    for(int i = 0 ; i < names.size(); i++)
    {
        cout << "Hello, " << names[i] << "!" << endl;
        cout << "Your average grade: " << grades[i] << endl;
    }
    
 


 


 
    return 0;
}

/*Answer: 
Get the constant number of grades up front via cin and then get them via a for and calculate as per the first program
Print all the users and average scores at the end
*/