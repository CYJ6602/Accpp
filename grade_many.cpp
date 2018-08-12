#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

  vector<string> name_list;
  vector<double> final_grade;
  string name;  
  double mid,fin;
  
  cout << "Enter the student's name" << endl;
  
  while(cin >> name)
    {  
      cout << "Enter student' midterm and final exam grades: ";
      
      cin >> mid >> fin;

      int num = 3;
      
      cout << "Enter the " << num << " homework grades." << endl;
	      
      int cnt=0;
      double sum=0;
      
      double x;
      vector<double> homework ;
      
      for(int i=0 ; i < num ; i++) {
	cin >> x;
	homework.push_back(x);
      }
      
      typedef vector<double>::size_type vec_sz;
      vec_sz size = homework.size();
      
      sort(homework.begin(), homework.end());
      
      vec_sz pmid = size/2;
      double median;
      median = size % 2 ==0 ? (homework[pmid-1] + homework[pmid])/2
	: homework[pmid] ;
      
      
      streamsize prec = cout.precision();
      cout << "Student's final grade is " << setprecision(3)
	   << 0.2 * mid + 0.4 * fin + 0.4 * median
	   << setprecision(prec) << endl;
      
      final_grade.push_back(0.2*mid+0.4*fin+0.4*median);

      cout << "Enter the next student's name: ";
      
    }
  
  return 0;
  
}
