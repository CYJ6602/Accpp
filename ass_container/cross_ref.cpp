#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "split.h"

using namespace std;

map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split)
{
  string line;
  int line_number = 0;
  map<string, vector<int> > ret;

  while(getline(in,line))
    {
      ++line_number;

      vector<string> words = find_words(line);

      for(vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
      ret[*it].push_back(line_number);
    }

  return ret;
}

int main()
{
  map<string, vector<int> > cref = xref(cin, split);
  
  for(map<string, vector<int> >::const_iterator it = cref.begin(); it != cref.end() ; ++it)
    {
      cout << it->first << "occurs on line(s) : " ;

      vector<int>::const_iterator vit = it->second.begin();
      
      cout << *vit ;
      ++vit;

      while(vit != it->second.end())
	{
	  cout << ", " << *vit;
	  ++vit;
	}

      cout << endl;

      /*
      for(vector<int>::const_iterator vit = (it->second).begin(); vit != (it->second).end() ; ++vit)
	cout << *vit << " " ;

	cout << endl;
      */
    }
  
  return 0;
}
  
