#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int k,t,n;
bitset<1000001> b;

void oneCase()
{
	int m;
	ll r;
	cin>>t;
	while (t--)
	{
		cin>>n;
		m=n+1;
		r=n;
		r=(r*(r+1))/2;
		cout<<(r&1)<<"\n";
		r/=2;
		for (int i=1;i<=n;++i)
			b[i]=0;
		while (r>0)
		{
			if (r>=m)
			{
				r-=(--m);
				b[m]=1;
			}
			else
			{
				b[r]=1;
				r=0;
			}
		}
		for (int i=1;i<=n;++i)
			cout<<b[i];
		cout<<"\n";
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>k;
    if (k==1)
    	oneCase();
    return 0;
}