#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t,n,cur;
	ll ans;
	string s;
	cin>>t;
	while (t--)
	{
		cin>>s;
		n=s.length();
		ans=0;
		for (int i=0;i<n;++i)
		{
			cur=0;
			for (int j=0;j<=i;++j)
			{
				if (s[i-j]=='1')
				{
					cur+=binpow(2,j);
				}
				if (cur==j+1)
				{
					++ans;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}