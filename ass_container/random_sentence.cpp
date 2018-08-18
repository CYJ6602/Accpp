#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <map>
#include <cstdlib>
#include "split.h"

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

Grammar read_grammar(istream& in)
{
  Grammar ret;
  string line;

  while(getline(in,line)) {
    vector<string> entry = split(line);

    if(!entry.empty())
      ret[entry[0]].push_back(Rule(entry.begin() +1, entry.end()));
      // entry[0] is category such as <noun>, <verb>, etc.
  }

  return ret;
}

Grammar read_grammar_line(vector<string> lines)
{
  Grammar ret;

  for(vector<string>::iterator it = lines.begin() ; it != lines.end() ; ++it)
    {
      vector<string> entry = split(*it);
      
      if(!entry.empty())
	ret[entry[0]].push_back(Rule(entry.begin() +1, entry.end()));
      // entry[0] is category such as <noun>, <verb>, etc.
    }

  return ret;
}



bool bracketed(const string& s)
{
  return s.size() > 1 && s[0] == '<' && s[s.size()-1] == '>';
}

int nrand(int n)
{
  if(n<=0 || n>RAND_MAX)
    throw domain_error("Argument to nrand is out of range");

  const int bucket_size = RAND_MAX / n;
  int r;

  do r = rand() / bucket_size;
  while(r >= n);

  return r;

}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
  if(!bracketed(word))
    ret.push_back(word);
  else
    {
      Grammar::const_iterator it = g.find(word);
      if(it == g.end())
	throw logic_error("empty rule");

      const Rule_collection& c = it->second;

      const Rule& r = c[nrand(c.size())];

      for(Rule::const_iterator i = r.begin() ; i != r.end() ; ++i)
	gen_aux(g, *i, ret);
    }
}


vector<string> gen_sentence(const Grammar& g)
{
  vector<string> ret;
  gen_aux(g, "<sentence>", ret);
  return ret;
}


  
int main()
{
  //  vector<string> sentence = gen_sentence(read_grammar(cin));  // to input by hand

  vector<string> lines;

  lines.push_back("<noun> cat");
  lines.push_back("<noun> dog");
  lines.push_back("<noun> table");
  lines.push_back("<noun-p> <noun>");
  lines.push_back("<noun-p> <adj> <noun-p>");
  lines.push_back("<adj> large");
  lines.push_back("<adj> brown");
  lines.push_back("<adj> absurd");
  lines.push_back("<verb> jumps");
  lines.push_back("<verb> sits");
  lines.push_back("<loc> on the stairs");
  lines.push_back("<loc> under the sky");
  lines.push_back("<loc> wherever it wants");
  lines.push_back("<sentence> the <noun-p> <verb> <loc>");
  
  
  Grammar g1 = read_grammar_line(lines);

  vector<string> sentence = gen_sentence(g1);
  
  vector<string>::const_iterator it = sentence.begin();
  if(!sentence.empty())
    {
      cout << *it;
      ++it;
    }

  while(it != sentence.end())
    {
      cout << " " << *it;
      ++it;
    }
  cout << endl;
  return 0;
}
