#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split(const string& s)
{
  vector<string> ret;
  typedef string::size_type string_size;
  string_size i=0;

  while(i != s.size())
    {
      while(i != s.size() && isspace(s[i]))
	++i; // i becomes start of string

      string_size j=i;

      while(j != s.size() && !isspace(s[j]))
	++j; // j becomes end of string( +1 : space)

      if(i != j) {
	ret.push_back(s.substr(i, j-i));
	i = j;
      }
    }
  return ret;
}

string::size_type width(const vector<string>& vec)
{
  string::size_type maxlen = 0;
  for(string::size_type i=0; i != vec.size() ; ++i)
    maxlen = max(maxlen, vec[i].size());

  return maxlen;
}

vector<string> frame(const vector<string>& vec)
{
  vector<string> ret;
  vector<string>::size_type wid = width(vec);
  string border(wid + 4,'*');

  ret.push_back(border);
  for(vector<string>::size_type i = 0 ; i != vec.size() ; ++i)
    {
      ret.push_back("* "+ vec[i] + string(wid - vec[i].size(),' ') + " *");
    }

  ret.push_back(border);

  return ret;
}


int main()
{
  cout << "Enter strings, "
    "or end of file : " ;
  
  string s;

  vector<string> combination;

  while( getline(cin,s) ) {
    vector<string> vec = split(s);

    vector<string> pic = frame(vec);
    
    for(vector<string>::const_iterator iter = pic.begin() ; iter != pic.end() ; ++iter)
      combination.push_back(*iter);
  } // this for-statement can be replaced by combination.insert(combination.end(),pic.begin(),pic.end());

  

  for(vector<string>::const_iterator iter = combination.begin() ; iter != combination.end() ; ++iter)
    cout << *iter << endl;
  
  return 0;
}
  
  

  
