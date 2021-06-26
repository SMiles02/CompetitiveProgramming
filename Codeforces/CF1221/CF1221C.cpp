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

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}
 
string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,c,m,x,k,ans;
	cin>>n;
	while (n--)
	{
		cin>>c>>m>>x;
		k=min({c,m,x});
		ans=k;
		c-=k;
		m-=k;
		x-=k;
		if (c>0&&m>0)
		{
			if (m>c)
			{
				swap(m,c);
			}
			if (c>=m*2)
			{
				ans+=m;
			}
			else
			{
				k=c-m;
				ans+=k;
				c-=(2*k);
				m-=k;
				k=(c/3);
				ans+=(2*k);
				m-=(3*k);
				c-=(3*k);
				if (c==2)
				{
					++ans;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}