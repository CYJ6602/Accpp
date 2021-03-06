#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using namespace std;

bool fgrade(const Student_info& s)
{
  return grade(s) < 60 ;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
  vector<Student_info> pass,fail;
  for(vector<Student_info>::size_type i=0 ; i!=students.size() ; ++i)
    if(fgrade(students[i]))
      fail.push_back(students[i]);
    else
      pass.push_back(students[i]);

  students=pass;
  return fail;
}

int main()
{
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen =0;

  while(read(cin,record)) {

    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare);

  vector<Student_info> fail = extract_fails(students);

  for(vector<Student_info>::size_type i=0 ; i != students.size() ; ++i)
    {
      cout << students[i].name
	   << string(maxlen + 1 - students[i].name.size(),' ');

      try {
	double final_grade = grade(students[i]);
	streamsize prec = cout.precision();
	cout << setprecision(3) << final_grade
	     << setprecision(prec);
      } catch (domain_error e) {
	cout << e.what();
      }

      cout << endl;
    }

  for(vector<Student_info>::size_type i=0 ; i != fail.size() ; ++i)
    {
      cout << fail[i].name
	   << string(maxlen + 1 - fail[i].name.size(),' ');

      try {
	double final_grade = grade(fail[i]);
	streamsize prec = cout.precision();
	cout << setprecision(3) << final_grade
	     << setprecision(prec);
      } catch (domain_error e) {
	cout << e.what();
      }

      cout <<endl;
    }
  
  return 0;
}
