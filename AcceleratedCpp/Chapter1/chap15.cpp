//Accelerated C++
//Chapter 1 Working with strings
//Question 1-5
#include <iostream>
#include <string>

int main(){
	
	{ std::string s= "a string";
	{ std::string x = s + ", really";
	std::cout << s << std::endl;	}
	std::cout << x << std::endl;
	}
	return 0;
}

/*Answer:The program is not valid because x is out of the scope of
 where it was declared.

 Rewritten to be valid

 #include <iostream>
#include <string>

int main(){
	
	{ std::string s= "a string";
	{ std::string x = s + ", really";
	std::cout << s << std::endl;	
	std::cout << x << std::endl;
	}
	}
	return 0;
}

this update program outputs 

"
a string
a string, really
"

*/