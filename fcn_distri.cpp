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

   vector<double> homework ;
 
   read_hw(cin, homework);
   
   try {
     double final_grade = grade(midterm, final, homework);
     streamsize prec = cout.precision();
     cout << "Your final grade is " << setprecision(3)
	  << final_grade << setprecision(prec) << endl;
   } catch(domain_error) {
     cout << endl << "You must enter your grades. "
       "Please try again." << endl;
     return 1;
   }

  return 0;
}
