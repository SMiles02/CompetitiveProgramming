#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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
    int n,m,ans=0;
    bool ok;
    cin>>n>>m;
    string s[n];
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int x=max(n,m);x;--x)
    {
        for (int i=0;i<n;++i)
        {
            for (int j=0;j+x<=m;++j)
            {
                ok=1;
                for (int k=j;k<j+x;++k)
                    if (s[i][k]=='.')
                    {
                        ok=0;
                        break;
                    }
                if (ok)
                {
                    ++ans;
                    for (int k=j;k<j+x;++k)
                        s[i][k]='.';
                }
            }
        }
        for (int j=0;j<m;++j)
        {
            for (int i=0;i+x<=n;++i)
            {
                ok=1;
                for (int k=i;k<i+x;++k)
                    if (s[k][j]=='.')
                    {
                        ok=0;
                        break;
                    }
                if (ok)
                {
                    ++ans;
                    for (int k=i;k<i+x;++k)
                        s[k][j]='.';    
                }
            }
        }
    }
    cout<<ans;
    return 0;
}