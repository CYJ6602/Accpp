#include "median.h"
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;


double median(vector<double> vec)
{
  typedef vector<double>::size_type vec_size;
  vec_size size = vec.size();
  if(size==0)
    throw domain_error("median of empty vector");

  sort(vec.begin(), vec.end());
  vec_size mid = size/2;

  vector<double>::iterator iter = vec.begin();
  
  return size % 2 == 0 ? (*(iter+mid-1)+*(iter+mid))/2 : *(iter+mid) ; 
}
