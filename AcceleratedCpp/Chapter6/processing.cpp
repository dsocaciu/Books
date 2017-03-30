#include <string>
#include "processing.h"

using std::string;

bool hasAscender(const string& input){
	for (int i =0; i < input.size();i++)
	{
		if (input[i] == 'b' || input[i] == 'd' || input[i] == 'f' || input[i] == 'h' || input[i] == 'k' || input[i] == 'l' || input[i] == 't')
			return true;
	}
	return false;
}

bool hasDescender(const string& input){
	for (int i =0; i < input.size();i++)
	{
		if (input[i] == 'g' || input[i] == 'j' || input[i] == 'p' || input[i] == 'q' || input[i] == 'y')
			return true;
	}
	return false;
}

