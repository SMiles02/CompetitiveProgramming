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
	int h,w,cur=1;
	cin>>h>>w;
    int r[h];
    int c[w];
    for (int i=0;i<h;++i)
    {
        cin>>r[i];
    }
    for (int i=0;i<w;++i)
    {
        cin>>c[i];
    }
    for (int i=0;i<h;++i)
    {
        for (int j=0;j<w;++j)
        {
            if (j==r[i])
            {
                if (i<c[j])
                {
                    cout<<0;
                    return 0;
                }
            }
            else
            {
                if (i==c[j])
                {
                    if (j<r[i])
                    {
                    	cout<<0;
                        return 0;
                    }
                }
                else if (j>r[i]&&i>c[j])
                {
                	cur*=2;
                	cur%=(1000000007);
                }
            }
        }
    }
    cout<<cur;
	return 0;
}