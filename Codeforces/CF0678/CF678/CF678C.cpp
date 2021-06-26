#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll LCM(int a, int b, int limiter)
{
	ll k;
	for (k = a; k <= limiter; k+=a)
	{
		if (k%b==0)
		{
			return k;
		}
	}
	return -1;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n, a, b, p, q, lcm;
  cin>>n>>a>>b>>p>>q;
  if (a>=b)
  {
  	lcm = LCM(a,b,n);
  }
  else
  {
  	lcm = LCM(b,a,n);
  }
  if (lcm == -1)
  {
  	cout<<(n/a)*p+(n/b)*q;
  }
  else if (p >= q)
  {
  	cout<<(n/a)*p+(n/b)*q-(n/lcm)*q;
  }
  else
  {
  	cout<<(n/a)*p+(n/b)*q-(n/lcm)*p;
  }
  return 0;
}