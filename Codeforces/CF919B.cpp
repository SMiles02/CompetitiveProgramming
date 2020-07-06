#include <bits/stdc++.h>
#define ll long long
using namespace std;

int perfection(int n)
{
	int ans = 0;
	while (n)
	{
		ans+=n%10;
		n/=10;
	}
	if (ans==10)
	{
		return true;
	}
	return false;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin>>n;
  m=18;
  while (n)
  {
  	m++;
  	if (perfection(m))
  	{
  		n--;
  	}
  }
  cout<<m;
  return 0;
}