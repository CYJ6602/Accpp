#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<class T>
T median(vector<T> v)
{
  typedef typename vector<T>::size_type v_sz;
  v_sz size =v.size();

  if(size==0)
    throw domain_error("median of an empty vector");

  sort(v.begin(),v.end());
  v_sz mid = size/2;

  return size%2 == 0 ? (v[mid-1]+v[mid])/2 : v[mid];
}

int main()
{
  vector<double> v;
  double x;
  while(cin>>x)
    v.push_back(x);

  double med = median(v);
  cout << "Median of vector is : " << med << endl;
  return 0;
}
