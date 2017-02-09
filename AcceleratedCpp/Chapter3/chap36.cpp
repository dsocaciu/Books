//Accelerated C++
//Chapter 3 Working with batches of data
//Question 3-6 

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
 
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
 
int main()
{

    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
 

    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
 

    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";
 

    int count = 0 ;
    double sum = 0.0;
 
    // a variable into which to read
    double x;
 

    while (cin >> x)
    {
        ++count;
        sum += x;
    }
 

    streamsize prec = cout.precision();
 
    if(count > 0){
     cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
         << setprecision(prec) << endl;
    }
 
    return 0;
}

/*Answer: 
Avoids this output 
Enter all your homework grades, followed by end-of-file: Your final grade is nan

*/