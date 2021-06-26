#include <bits/stdc++.h>
#define ll long long
using namespace std;

string dp(ll n, ll k)
{
	ll table[n+1];
	table[0]=0;
	if (n > 0)
	{
		table[1] = 1;
	}
	for (ll i = 2; i<=n;i++)
	{
		if (i < k)
		{
			if (table[i-1] + table[i-2] < 2)
			{
				table[i] = 1;
			}
			else
			{
				table[i] = 0;
			}
		}
		else
		{
			if (table[i-1] + table[i-2] + table[i-k] < 3)
			{
				table[i] = 1;
			}
			else
			{
				table[i] = 0;
			}
		}
	}
	//for (int i = 0; i<=n; i++)
	//{
	//	cout << table[i] << " ";
	//}
	//cout<<"\n";
	if (table[n] == 0)
	{
		return "Bob";
	}
	else
	{
		return "Alice";
	}
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll t,n,k,i;
  cin>>t;
  for (i=0;i<t;i++)
  {
  	cin>>n>>k;
  	cout<<dp(n,k)<<"\n";
  }
  return 0;
}