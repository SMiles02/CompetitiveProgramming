#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll l, r;
  cin>>l>>r;
  if (r-l < 2 || r == 3)
  {
  	cout<<-1;
  }
  else if (r%2==1)
  {
  	if (r-l == 2)
  	{
  		cout<<-1;
  	}
  	else
  	{
  		cout<<r-3<<" "<<r-2<<" "<<r-1;
  	}
  }
  else
  {
  	cout<<r-2<<" "<<r-1<<" "<<r;
  }
  return 0;
}