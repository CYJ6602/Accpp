#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

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

double grade(double midterm, double final, double homework)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
  if (hw.size()==0)
    throw domain_error("student has done no homework");
  return grade(midterm,final,median(hw));
}

istream& read_hw(istream& in, vector<double>& hw)
{
  if(in){
    hw.clear();

    double x;
    while (in >>x)
      hw.push_back(x);

    in.clear();
  }
  return in;
}


int main()
{
  cout << "Enter your first name: " ;
  string name;
  cin >> name;
  cout << "Nice to meet you, " << name << endl ;

  cout << "Enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  cout << "Enter your homework grades, "
    "followed by endoffile: ";

  double x;
  vector<double> homework ;
   
  //invariant : homework contain all homework contain which read until now
 
  while(cin>>x) {
    homework.push_back(x);
  }

  cout << "Your final grade is " << grade(midterm,final,homework) << endl;

  return 0;
}
