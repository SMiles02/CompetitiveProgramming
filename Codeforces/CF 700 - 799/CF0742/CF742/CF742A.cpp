#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  if (n==0)
  {
  	cout<<1;
  }
  else if (n%4==0)
  {
  	cout<<6;
  }
  else if (n%4==1)
  {
  	cout<<8;
  }
  else if (n%4==2)
  {
  	cout<<4;
  }
  else if (n%4==3)
  {
  	cout<<2;
  }

  return 0;
}