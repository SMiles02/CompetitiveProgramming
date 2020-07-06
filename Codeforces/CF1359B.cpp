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

void solve()
{
    int n,m,x,y,ans=0;
    cin>>n>>m>>x>>y;
    string s[n];
    y=min(y,2*x);
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<m-1;++j)
        {
            if (s[i][j]=='.')
            {
                if (s[i][j+1]=='.')
                {
                    ans+=y;
                    s[i][j]='*';
                    s[i][j+1]='*';
                }
                else
                {
                    ans+=x;
                    s[i][j]='*';
                }
            }
        }
        if (s[i][m-1]=='.')
            ans+=x;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}