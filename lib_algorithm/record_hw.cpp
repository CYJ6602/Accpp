#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include "Student_info.h"
#include "grade.h"
#include "median.h"

using namespace std;

bool did_all_hw(const Student_info& s)
{
  return ((find(s.homework.begin(), s.homework.end(),0)) == s.homework.end());
}

double grade_aux(const Student_info& s)
{
  try{
    return grade(s);
  } catch(domain_error){
    return grade(s.midterm, s.final, 0);
  }
}

double median_analysis(const vector<Student_info>& students)
{
  vector<double> grades;
  transform(students.begin(),students.end(),back_inserter(grades),grade_aux);
  return median(grades);
}

void write_analysis(ostream& out, const string& name,
		    double analysis(const vector<Student_info>&),
		    const vector<Student_info>& did,
		    const vector<Student_info>& didnt)
{
  out << name << ": median(did) = " << analysis(did) <<
    ", median(didnt) = " << analysis(didnt) << endl;
}

double average(const vector<double>& v)
{
  return accumulate(v.begin(),v.end(),0.0)/v.size();
}

double average_grade(const Student_info& s)
{
  return grade(s.midterm,s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
  vector<double> grades;
  transform(students.begin(),students.end(), back_inserter(grades), average_grade);
  return median(grades);
}

double optimistic_median(const Student_info& s)
{
  vector<double> nonzero;
  remove_copy(s.homework.begin(),s.homework.end(),back_inserter(nonzero),0);
  if(nonzero.empty())
    return grade(s.midterm,s.final,0);
  else
    return grade(s.midterm,s.final,median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
  vector<double> grades;
  transform(students.begin(),students.end(),back_inserter(grades),optimistic_median);
  return median(grades);
}

bool fgrade(const Student_info& s)
{
  return grade(s) < 60 ;
}

bool pgrade(const Student_info& s)
{
  return !fgrade(s);
}

vector<Student_info> two_pass_extract_fail(vector<Student_info>& students)
{
  vector<Student_info> fail;
  remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
  students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());

  return fail;
}
  
vector<Student_info> one_pass_extract_fail(vector<Student_info>& students)
{
  vector<Student_info>::iterator iter;
  iter = stable_partition(students.begin(),students.end(),pgrade);
  vector<Student_info> fail(iter, students.end());
  students.erase(iter,students.end());

  return fail;
}


int main()
{
  
  vector<Student_info> did, didnt, all;
  Student_info student;
  
  while(read(cin,student))
    {
      all.push_back(student);
      
      if(did_all_hw(student))
	did.push_back(student);
      else
	didnt.push_back(student);
    }

  if(did.empty())
    {
      cout << "No student did all the hw" << endl;
      return 1;
    }
  
  if(didnt.empty())
    {
      cout << "Every student did all the hw" << endl;
      return 1;
    }
  
  write_analysis(cout,"median", median_analysis, did, didnt);
  write_analysis(cout,"average", average_analysis, did, didnt);
  write_analysis(cout,"median of hw turned in", optimistic_median_analysis, did, didnt);

  vector<Student_info> fail = one_pass_extract_fail(all);
  for(vector<Student_info>::const_iterator iter = all.begin(); iter != all.end(); iter++)
    cout << iter->name << " : pass" << endl;

  for(vector<Student_info>::const_iterator iter = fail.begin(); iter != fail.end(); iter++)
    cout << iter->name << " : fail" << endl;
  
  return 0;
   
}

