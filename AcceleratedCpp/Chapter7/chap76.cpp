//Accelerated C++
//Chapter 7 Using associative containers
//Question 7-6


#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using std::cin;		using std::cout;		using std::endl;	
using std::map;		using std::string;		using std::vector;
using std::istream;	using std::logic_error;	using std::domain_error;

int nrand(int n)
{
	if (n <=0 || n > RAND_MAX)
		throw domain_error("Argument to nrand is out of range");

	const int bucket_size = RAND_MAX / n;

	int r;

	do r = rand() / bucket_size;
	while( r >= n);


	return r;
}

bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}


vector<string> split (const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while ( i!=str.end()){

		//ignore leading blank
		i = find_if(i, str.end(), not_space);

		//find end of next word
		iter j = find_if(i, str.end(),space);

		//copy the characters in [i,j)
		if ( i != str.end())
			ret.push_back(string(i,j));
		i=j;
	}
	return ret;
}

typedef vector<string> Rule;
typedef vector<Rule> RuleCollection;
typedef map<string, RuleCollection> Grammar;

Grammar read_grammar(istream& in)
{
	Grammar ret;
	string line;

	//read the input
	while(getline(in ,line)){
		
		//split the input into words
		vector<string> entry = split(line);
		if(!entry.empty())
			//use the category to store the associated rule
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));

	}

	return ret;

}

/*

bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& word, vector<string>& sentence, vector<string>& token)
{
	if(!bracketed(word)){
		setence.push_back(word);
	}
	else{
		//locate the rule that corresponds to the word
		Grammar::const_iterator it = g.find(word);
		if(it == g.end())
			throw logic_error("empty rule");

		//fetch the set of possible rules
		const RuleCollection& c = it->second;

		//from which we select one at random
		const Rule& r = c[nrand(c.size())];

		//recursively expand the selected rule
		for(Rule::const_iterator  i = r.begin(); i != r.end(); ++i)
			gen_aux(g,*i,ret);
	}
}

vector<string> gen_sentence(const Grammar& g)
{
	vector<string> sentence;
	vector<string> tokens;
	//vector<string> ret;
	//gen_aux(g,"<sentence>",ret);



	return sentence;
}*/

void gen_aux(const Grammar&, const string&, vector<string>&, vector<string>&);



vector<string> gen_sentence(const Grammar& g) {
  vector<string> sentence;
  vector<string> tokens;
  tokens.push_back("<sentence>");

  while (!tokens.empty()) {
    string token = tokens.back();
    tokens.pop_back();
    gen_aux(g, token, sentence, tokens);
  }

  return sentence;
}

bool bracketed(const string& s) {
  return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& token, 
	     vector<string>& sentence, vector<string>& tokens) {
  if (!bracketed(token)) {
    sentence.push_back(token);
  } else {
    // locate the rule that corresponds to `token'
    Grammar::const_iterator it = g.find(token);

    if (it == g.end())
      throw logic_error("empty rule");

    // fetch the set of possible rules
    const RuleCollection& c = it->second;

    // from which we select one at random
    const Rule& r = c[nrand(c.size())];

    // push rule's tokens onto stack of tokens
    // (in reverse order, because we're pushing and popping from the back)
    for (Rule::const_reverse_iterator i = r.rbegin(); i != r.rend(); ++i)
      tokens.push_back(*i);
  }
}


int main()
{
	
	//generate the sentence 
	vector<string> sentence = gen_sentence(read_grammar(cin));

	//write the first word, if any
	vector<string>::const_iterator it = sentence.begin();
	if(!sentence.empty()){
		cout << *it;
		++it;
	}

	//write the rest of the words, each preceded by a space
	while(it != sentence.end()){
		cout << " " << *it;
		++it;

	}

	cout << endl;
}

//Answer: This piece was taken from the author's answer code