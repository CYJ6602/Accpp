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

  sort(vec.begin(),vec.end());
  vec_size mid = size/2;

  return size % 2 == 0 ? (vec[mid-1]+vec[mid])/2 : vec[mid] ;
}
