#include <iostream>

using namespace std;

void
swap (int a, int b)
{

  int t = a;
  a = b;
  b = t;
}


int
main ()
{
  int a;
  cin>>a;
  int b;
  cin>>b;

  swap(a,b);
  cout<<b<<" "<<a<<endl;

  return 0;
}

