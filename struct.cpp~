#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  cout << "Enter your first name: " ;
  string name;
  cin >> name;
  cout << "Nice to meet you, " << name << endl ;

  cout << "Enter your midterm and final exam grades: ";
  double mid,fin;
  cin >> mid >> fin;

  cout << "Enter your homework grades, "
    "followed by endoffile: ";

  int cnt=0;
  double sum=0;

  double x;
  vector<double> homework ;
   
  //invariant : homework contain all homework contain which read until now
 
  while(cin>>x) {
    homework.push_back(x);
  }

  typedef vector<double>::size_type vec_sz;
  vec_sz size = homework.size();

  if(size==0)
    {
      cout << "You must enter your grade. "
	"Please try again." << endl;

      return 1;
    }
  
  sort(homework.begin(), homework.end());

  vec_sz pmid = size/2;
  double median;
  median = size % 2 ==0 ? (homework[pmid-1] + homework[pmid])/2
    : homework[pmid] ;

  
  streamsize prec = cout.precision();
  cout << "Your final grad is " << setprecision(3)
       << 0.2 * mid + 0.4 * fin + 0.4 * median
       << setprecision(prec) << endl;

  cout << "Prec is " << prec << endl;

  return 0;
}
