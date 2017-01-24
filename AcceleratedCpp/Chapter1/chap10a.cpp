//Accelerated C++
//Chapter 1 Working with strings
//Question 1-0 first

#include <iostream>
#include <string>
 
int main()
{

    std::cout << "Please enter your first name: ";
 
    std::string name;   //define name
    std::cin >> name;   //read into name
 
    std::cout << "Hello, " << name << "!" << std::endl;
    return 0;
}

/*Answer: The code compiles simply 'g++ -o chap10a.o chap10a.cpp' on a Mac terminal
*/