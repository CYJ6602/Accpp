#include <iostream>

using namespace std;

template<class T>
T max(T left, T right)
{
  return left > right ? left : right;
}

int main()
{
  /*
  double x,y;
  cout << "Input two double variable : " ;
  cin >> x >> y;
  cout << endl;

  int a,b;
  cout << "Input two int variable : " ;
  cin >> a >> b;
  cout << endl;  
  */
  
  cout << "Max of doubles : " << max(10.5,20.0) << endl;
  cout << "Max of int : " << max(10,20) << endl;

  return 0;
}
