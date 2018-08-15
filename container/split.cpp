#include <iostream>
#include <vector>
#include <cctype>
#include <string>

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


int main()
{
  cout << "Enter strings, "
    "or end of file : " ;
  
  string s;

  while( getline(cin,s) ) {
    vector<string> vec = split(s);
    
    for(vector<string>::const_iterator iter = vec.begin() ; iter != vec.end() ; ++iter)
      cout << *iter << endl;
  }

  return 0;
}
  
  

  
