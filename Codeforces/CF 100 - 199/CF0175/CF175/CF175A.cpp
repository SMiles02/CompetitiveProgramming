#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
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
    int n,x,cur,ans=-1;
    string s;
    cin>>s;
    n=sz(s);
    for (int i=0;i<n;++i)
        for (int j=i+1;j+1<n;++j)
            {
                if (s[0]=='0'&&i+1>1)
                    continue;
                if (s[i+1]=='0'&&j-i>1)
                    continue;
                if (s[j+1]=='0'&&n-j-1>1)
                    continue;
                cur=0;
                if (i+1>7)
                    continue;
                else
                {
                    x=0;
                    for (int l=0;l<=i;++l)
                    {
                        x*=10;
                        x+=(s[l]-'0');
                    }
                    if (x>1e6)
                        continue;
                    cur+=x;
                }
                if (j-i>7)
                    continue;
                else
                {
                    x=0;
                    for (int l=i+1;l<=j;++l)
                    {
                        x*=10;
                        x+=(s[l]-'0');
                    }
                    if (x>1e6)
                        continue;
                    cur+=x;
                }
                if (n-j-1>7)
                    continue;
                else
                {
                    x=0;
                    for (int l=j+1;l<n;++l)
                    {
                        x*=10;
                        x+=(s[l]-'0');
                    }
                    if (x>1e6)
                        continue;
                    cur+=x;
                }
                ans=max(ans,cur);
            }
    cout<<ans;
    return 0;
}